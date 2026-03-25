
#include <catch2/catch_test_macros.hpp>
#include <ranges>
#include <string>
#include <vector>

int iseven(int val) { return val % 2; }

template <std::ranges::viewable_range R>
std::string to_string(R rng) {
  auto v = std::ranges::views::common(rng);
  return std::string(v.begin(), v.end());
}

// Принципиальная схема простейшего адаптера
struct to_str_closure {
  template <typename R>
  auto operator()(R r) const {
    return to_string(r);
  }
};

struct to_str_adaptor {
  // берет R и возвращает to_string(R)
  template <typename R>
  auto operator()(R r) {
    return to_string(r);
  }
  // конструирует и возвращает closure, тут можно было вернуть лямбду,
  // но тогда не получится перегрузить оператора pipe.
  auto operator()() { return to_str_closure(); }
};

template <typename R>
auto operator|(R r, const to_str_closure& c) {
  return c(r);
}

inline to_str_adaptor to_str;

TEST_CASE("1") {
  std::vector v{'a', 'b', 'c', 'd'};
  auto vf = v | std::views::filter([](int n) { return n % 2; });
  auto s = to_string(vf);
  REQUIRE(s == "ac");
}

TEST_CASE("2_pipe") {
  std::vector v{'a', 'b', 'c', 'd'};
  auto vf = v | std::views::filter([](int n) { return n % 2; });
  // to_str вызывает () получается closure, для которого перегружен pipe
  auto s = v | std::ranges::views::filter(iseven) | to_str();
  REQUIRE(s == "ac");
}