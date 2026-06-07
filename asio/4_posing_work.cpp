
#include <boost/asio.hpp>
#include <iostream>


int main() {
    namespace asio=boost::asio;

    asio::io_context service;

    boost::asio::post(service,[]{std::cout <<"eat\n";});
    boost::asio::post(service,[]{std::cout <<"drink\n";});
    boost::asio::post(service,[]{std::cout <<"and be merry\n";});

    std::thread butler([&]{service.run();});

    butler.join();

    std::cout << "done."<<std::endl;
}