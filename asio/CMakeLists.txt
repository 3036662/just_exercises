

find_package(Boost REQUIRED COMPONENTS system )

add_executable(simple_timer 1_simple_timer.cpp)
target_link_libraries(simple_timer PRIVATE Boost::boost)

add_executable(timer_with_threads 2_timer_with_threads.cpp)
target_link_libraries(timer_with_threads PRIVATE Boost::boost)

add_executable(timer_with_two_threads 3_timer_with_two_threads.cpp)
target_link_libraries(timer_with_two_threads PRIVATE Boost::boost)

add_executable(posting_work 4_posing_work.cpp)
target_link_libraries(posting_work PRIVATE Boost::boost)

add_executable(strand 5_strand.cpp)
target_link_libraries(strand PRIVATE Boost::boost)

add_executable(generic_server 6_generic_server.cpp)
target_link_libraries(generic_server PRIVATE Boost::boost)
