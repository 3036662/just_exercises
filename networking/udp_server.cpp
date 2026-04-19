#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#include <catch2/catch_test_macros.hpp>
#include <future>
#include <iostream>
#include <ranges>
#include <thread>

void Client(sockaddr_in server_address) {
  // give the server time to start
  std::this_thread::sleep_for(std::chrono::seconds(2));
  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  REQUIRE(sock != -1);
  char buffer[1024]{};
  for (const auto i : std::ranges::views::iota(1, 10)) {
    const auto mess = std::to_string(i);
    std::cout << "SEND TO SERVER: " << mess << std::endl;
    auto p_serv_addr = reinterpret_cast<sockaddr*>(&server_address);
    const auto sent = sendto(sock, mess.c_str(), mess.length(), 0, p_serv_addr,
                             sizeof(server_address));
    REQUIRE(sent != -1);
    std::memset(buffer, 0x00, 1024);
    int n = recvfrom(sock, buffer, 1024, 0, nullptr, nullptr);
    REQUIRE(n != -1);
    REQUIRE(std::string(buffer) == mess);
  }
  REQUIRE(close(sock) == 0);
}

TEST_CASE("start") {
  protoent* proto = getprotobyname("udp");
  REQUIRE(proto != nullptr);
  const int protocol_num = proto->p_proto;
  endprotoent();
  int sock = socket(AF_INET, SOCK_DGRAM, protocol_num);
  REQUIRE(sock != -1);

  sockaddr_in sock_addr{.sin_family = AF_INET,
                        .sin_port = htons(8080),
                        .sin_addr = in_addr{.s_addr = inet_addr("127.0.0.1")}};
  sockaddr* ptr_sock_addr = reinterpret_cast<sockaddr*>(&sock_addr);
  const int bind_res = bind(sock, ptr_sock_addr, sizeof(sock_addr));
  REQUIRE(bind_res == 0);
  char buff[1024]{};

  sockaddr_in client_addr{};
  sockaddr* ptr_client_addr = reinterpret_cast<sockaddr*>(&client_addr);
  socklen_t client_addr_len = sizeof(client_addr);

  // launch the client
  auto client_ft = std::async(std::launch::async, Client, sock_addr);

  // read from client
  for (const auto i : std::ranges::views::iota(1, 10)) {
    memset(buff, 0x00, 1024);
    int n =
      recvfrom(sock, buff, sizeof(buff), 0, ptr_client_addr, &client_addr_len);
    REQUIRE(n != -1);
    if (n == 0) {
      break;
    }

    const std::string client_ip = inet_ntoa(client_addr.sin_addr);
    const int client_port = ntohs(client_addr.sin_port);
    const std::string_view msg(buff);
    std::cout << "Received from client: " << client_ip << ":" << client_port
              << " -> " << msg << std::endl;
    auto sent =
      sendto(sock, buff, msg.size(), 0, ptr_client_addr, client_addr_len);
    REQUIRE(sent != -1);
  }

  REQUIRE(close(sock) == 0);
  client_ft.wait();
}
