  #include <iostream>
  #include <string>
  #include <utility>

  struct A {
    std::string a_;
    std::string b_;

    A(const std::string& a, std::string&& b) : a_{a}, b_{std::move(b)} {
      std::cout << "A Constructor \n";
      std::cout << "a (not moved)" << a << "\n";
      std::cout << "b (already moved) " << b << "\n";
    }
  };

  template <typename T, typename T1>
  T create(T1&& t1) {
    return T(std::forward<T1>(t1));
  }

  template <typename T, typename... Args>
  //T create_var(Args&&... args)=delete;
  T create_var(Args&&... args) {
    return T(std::forward<Args>(args)...);
  }

  int main() {
    std::cout << std::endl;

    // Lvalues
    int five = 5;
    int myFive = create<int>(five);
    std::cout << "myFive: " << myFive << std::endl;

    std::string str{"Lvalue"};
    std::string str2 = create<std::string>(str);
    std::cout << "str2: " << str2 << std::endl;

    // Rvalues
    int myFive2 = create<int>(5);
    std::cout << "myFive2: " << myFive2 << std::endl;

    std::string str3 = create<std::string>(std::string("Rvalue"));
    std::cout << "str3: " << str3 << std::endl;

    std::string str4 = create<std::string>(std::move(str3));
    std::cout << "str4: " << str4 << std::endl;

    std::cout << std::endl;

    using namespace std::literals;
    auto a = "xxxx"s;
    const A a_obj = create_var<A>("aaaa"s, std::move(a));
    std::cout << a_obj.a_ << " " << a_obj.b_ << "\n";
    std::cout << "source a = "<<a<<"\n";
  };
  // clang++ 3_perf_forwading.cpp -o 3_perf_forwading -Wall -Wextra