add_executable(udp_echo_server udp_server.cpp)

target_link_libraries(udp_echo_server PRIVATE Catch2::Catch2WithMain)