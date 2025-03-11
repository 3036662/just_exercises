#include <cmath>
#include <iostream>
#include <string>
#include <array>


// if the overload set includes a literal operator with the parameter type unsigned long long,
// the user-defined literal expression is treated as a function call operator ""X(n ﻿ULL)
long operator ""_huebin (unsigned long long h){
 return h;
}

// otherwise, the overload set must include either, but not both, a raw literal operator or a
// numeric literal operator template. If the overload set includes a raw literal operator,
// the user-defined literal expression is treated as a function call operator""X("n ﻿");
long operator "" _sh (const char* h){
    return std::stoi(h);
}



// otherwise, if the overload set includes a numeric literal operator template, 
// the user-defined literal expression is treated as a function call operator""X<'c1 ﻿', 'c2 ﻿', 'c3 ﻿'..., 'ck ﻿'>(), 
// where c1..ck are the individual characters of n and all of them are from the basic character set.

long unpack(){
    return 0;
}

template <char Head='x', char... Tail>
long unpack() {
    std::cout << "head ="<<Head<<"\n";
    if (Head=='x'){return 0;}
    return std::stoi(std::string(1,Head))* std::pow(10, sizeof...(Tail)) + unpack<Tail...>();
}

template <char ... Args> 
long operator "" _v (){
    return unpack<Args...>();
}


// ---
// folding
template <char ... Args> 
long operator "" _vv (){
    std::string s;
    ((s +=  Args),...); // fold
    return std::stoi(s);
}


// unpack with array
template  <char ... Args>
long operator "" _vvv(){
    std::array<char,sizeof...(Args)> arr{Args...};
    return std::stoi(std::string(arr.data()));
}


int main(){

    auto x=111_huebin;
    std::cout << "x = " << x << "\n";

    auto sh = 500_sh;
    std::cout << "sh = " << sh << "\n";

    auto v = 101_v;
    std::cout << "v = " << v << "\n";

    auto vv = 51013_vv;
    std::cout << "vv = " << vv << "\n";

    auto vvv = 3510133_vvv;
    std::cout << "vvv = " << vvv << "\n";
}

// clang++ 1_user_literals.cpp -o 1_user_literals -Wall -Wextra