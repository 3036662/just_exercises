
#include <catch2/catch_test_macros.hpp>
#include <list>
#include <ranges>
#include <span>
#include <iostream>

template <std::ranges::viewable_range T>
size_t count_list(T list){
   if (std::ranges::empty(list)){return 0;}
   auto subrange=std::ranges::subrange(std::next(std::ranges::begin(list)),std::ranges::end(list));
   return 1+count_list(subrange);
}


TEST_CASE("1")
{
    std::vector<int> lst{1,2,3,4,5,6};
    REQUIRE(count_list(lst)==6);
}

TEST_CASE("2")
{
    std::list<int> lst{1,2,3,4,5,6,0};
    REQUIRE(count_list(lst)==7);
}

TEST_CASE("3")
{
  std::list<int> lst{};
  REQUIRE(count_list(lst)==0);
}