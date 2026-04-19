add_executable(udp_echo_server udp_echo_server.cpp)

target_link_libraries(udp_echo_server PRIVATE Catch2::Catch2WithMain)

add_executable(tcp_echo_server tcp_echo_server.cpp)

target_link_libraries(tcp_echo_server PRIVATE Catch2::Catch2WithMain)