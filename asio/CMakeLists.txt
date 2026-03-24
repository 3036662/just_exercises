

find_package(Boost REQUIRED COMPONENTS system )

add_executable(simple_timer 1_simple_timer.cpp)

add_executable(timer_with_threads 2_timer_with_threads.cpp)

add_executable(timer_with_two_threads 3_timer_with_two_threads.cpp)

add_executable(posting_work 4_posing_work.cpp)

add_executable(strand 5_strand.cpp)

add_executable(generic_server 6_generic_server.cpp)