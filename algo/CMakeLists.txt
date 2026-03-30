
add_executable(1_list_el_count 1_list_el_count.cpp)
find_package(Catch2 REQUIRED)

add_test(1_list_el_count 1_list_el_count)
target_link_libraries(1_list_el_count PRIVATE Catch2::Catch2WithMain)
