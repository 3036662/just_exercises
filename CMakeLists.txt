cmake_minimum_required(VERSION 4.2)
project(just_exercises)

set(CMAKE_CXX_STANDARD 20)



find_package(Catch2 REQUIRED)

enable_testing()




add_subdirectory(asio)
add_subdirectory(algo)
add_subdirectory(networking)

add_executable(1_user_literals 1_user_literals.cpp)

add_executable(2_big_array 2_big_array.cpp)

add_executable(3_perf_forwading 3_perf_forwading.cpp)

add_executable(4_ptr_bench 4_ptr_bench.cpp)

add_executable(5_move_semantics 5_move_semantics.cpp)

add_executable(6_variadic_factory 6_variadic_factory.cpp)

add_executable(7_type_deduction 7_type_deduction.cpp)

add_executable(8_hw_concurrency 8_hw_concurrency.cpp)

add_executable(9_thread_sleep 9_thread_sleep.cpp)

add_executable(10_map_shared 10_map_shared.cpp)

add_executable(11_call_once_singleton 11_call_once_singleton.cpp)

add_executable(12_cond_var 12_cond_var.cpp)

add_executable(13_multhithreaded_inner_product 13_multhithreaded_inner_product.cpp)

add_executable(14_packaged_task 14_packaged_task.cpp)

add_executable(15_exceprion_ptr 15_exceprion_ptr.cpp)

add_executable(16_non_type_templ 16_non_type_templ.cpp)

add_executable(17_visit 17_visit.cpp)

add_executable(18_less_concept_cpp20 18_less_concept_cpp20.cpp)

add_executable(19_spin_lock 19_spin_lock.cpp)

add_executable(20_viewable_range 20_viewable_range.cpp)
target_link_libraries(20_viewable_range PRIVATE Catch2::Catch2WithMain)

add_executable(21_templ_spec 21_templ_spec.cpp)
target_link_libraries(21_templ_spec PRIVATE Catch2::Catch2WithMain)