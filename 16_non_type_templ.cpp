#include <cstddef>
#include <iostream>

/*
Implement four different class templates which accept an integral, a pointer, a reference, or a nullptr as a non-type parameter. You need to display the type of data passed as a parameter.
*/

template <char CH>
class AcceptChar{
public:
    AcceptChar(){
        std::cout <<"char :"<<CH<<"\n";
    }
};


template <void(*func)()>
class AcceptFunction{
public:
    AcceptFunction(){
        std::cout <<"func pointer :"<<func<<"\n";
    }
};

template <int sz,const int(&arr)[sz]>
class AcceptReference{
public:
    AcceptReference(){
        std::cout <<"arr pointer :"<<arr<<" size:"<<sz<<"\n";
    }
};

template <std::nullptr_t ptr>
class AcceptNullptr{
public:
    AcceptNullptr(){
        std::cout <<"nullptr_t pointer: "<<ptr<<"\n";
    }
};

void myFunc(){}

constexpr int arr[3]{};

int main() {
  
  
  AcceptChar<'c'> acceptChar;
  AcceptFunction<myFunc> acceptFunction;
  AcceptReference<3,arr> acceptReference;
  AcceptNullptr< nullptr > acceptNullptr;
}