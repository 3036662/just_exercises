
#include <boost/asio.hpp>
#include <iostream>


int main() {
    namespace asio=boost::asio;

    asio::io_service service;

    service.post([]{std::cout <<"eat\n";});
    service.post([]{std::cout <<"drink\n";});
    service.post([]{std::cout <<"and be merry\n";});

    std::thread butler([&]{service.run();});

    butler.join();

    std::cout << "done."<<std::endl;
}