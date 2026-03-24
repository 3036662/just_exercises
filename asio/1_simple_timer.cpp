
#include <boost/asio.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <iostream>

int main() {
    namespace asio=boost::asio;

    asio::io_service service;
    asio::deadline_timer timer(service, boost::posix_time::seconds(5));

    timer.async_wait([](auto ...vn) {
        std::cout << std::chrono::system_clock::now() << " : timer expired.\n";
    });

    std::cout << std::chrono::system_clock::now() << ": calling run\n";

    service.run();

    std::cout << std::chrono::system_clock::now() << " : done.\n";

}
