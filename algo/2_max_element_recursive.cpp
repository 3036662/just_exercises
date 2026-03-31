
#include <catch2/catch_test_macros.hpp>
#include <list>
#include <ranges>
#include <span>
#include <iostream>


template <std::ranges::viewable_range R>
auto MaxElementRecursive(R range) {
  if (std::ranges::empty(range)) {
    throw std::runtime_error("Empty range");
  }
  const auto sz=std::ranges::size(range);
  if (sz==1) {
    return range[0];
  }
  if (sz==2) {
    return std::max(range[0], range[1]);
  }
  auto subrange=std::ranges::subrange(std::ranges::next(std::ranges::begin(range)),std::ranges::end(range));
  return std::max(range[0],MaxElementRecursive(subrange));
}

TEST_CASE("Test1") {
  SECTION("Empty") {
    REQUIRE_THROWS(MaxElementRecursive(std::vector<int>{}));
  }

  SECTION("1") {
    REQUIRE(MaxElementRecursive(std::vector<int>{1,2,3,4})==4);
  }

  SECTION("2") {
    REQUIRE(MaxElementRecursive(std::vector<int>{1,-244,3,144})==144);
  }

  SECTION("2") {
    REQUIRE(MaxElementRecursive(std::vector<int>{0,0,0,0})==0);
  }
  SECTION("3") {
    REQUIRE(MaxElementRecursive(std::vector<int>{5})==5);
  }
}

