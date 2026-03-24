
#include <boost/asio.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <iostream>

void timer_expired(std::string id) {
    std::cout << std::chrono::system_clock::now() << " " <<id << " enter.\n";
    std::this_thread::sleep_for((std::chrono::seconds(3)));
    std::cout << std::chrono::system_clock::now() << " " <<id << " leave.\n";
}

int main() {
    namespace asio=boost::asio;

    asio::io_service service;

    asio::deadline_timer timer1(service,boost::posix_time::seconds(5));
    asio::deadline_timer timer2(service,boost::posix_time::seconds(5));

    timer1.async_wait([](auto...n){ timer_expired("timer1");});
    timer2.async_wait([](auto...n){timer_expired("timer2");});

    // the butler can only deliver one result at a time.
    std::thread ta([&]{service.run();});
    std::thread tb([&]{service.run();});

    ta.join();
    tb.join();

    std::cout << "done.\n";
}

// 2026-03-17 11:06:11.799421508 timer1 enter.
// 2026-03-17 11:06:11.799445219 timer2 enter.
// 2026-03-17 11:06:14.799654899 timer1 leave.
// 2026-03-17 11:06:14.799666569 timer2 leave.
