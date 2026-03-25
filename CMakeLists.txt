cmake_minimum_required(VERSION 4.2)
project(just_exercises)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(asio)

find_package(Catch2 REQUIRED)

enable_testing()
add_executable(19_viewable_range 19_viewable_range.cpp)
target_link_libraries(19_viewable_range PRIVATE Catch2::Catch2WithMain)