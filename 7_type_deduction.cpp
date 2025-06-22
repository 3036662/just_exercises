#include <ios>
#include <iostream>
#include <type_traits>
#include <utility>

template <typename D>
void del(D)=delete;

template <typename  T>
void simple(T val){
    std::cout <<"simple\n";
     if (std::is_same_v<T, int>){
        std::cout <<"T == int "<< std::is_same_v<T, int><<"\n";
    }
    if (std::is_same_v<T,const int>){
        std::cout <<"T == const int "<< std::is_same_v<T,const int><<"\n";
    }
    if (std::is_same_v<T, int&>){
        std::cout <<"T == int& "<< std::is_same_v<T, int&><<"\n";
    }
    if (std::is_same_v<T, int&&>){
        std::cout <<"T == int&& "<< std::is_same_v<T, int&&><<"\n";
    }
    if (std::is_same_v<T,const int&>){
        std::cout <<"T == const int& "<< std::is_same_v<T,const int&><<"\n";
    }
    if (std::is_same_v<T,const int&&>){
        std::cout <<"T == const int&& "<< std::is_same_v<T,const int&&><<"\n";
    }
    if (std::is_same_v<T, int*>){
        std::cout <<"T == int* "<< std::is_same_v<T, int*><<"\n";
    }
    if (std::is_same_v<T,const int*>){
        std::cout <<"T ==const int* "<< std::is_same_v<T,const int*><<"\n";
    }


    if (std::is_same_v<int, decltype(val)>){
        std::cout <<"decltype(val) == int "<< std::is_same_v<int, decltype(val)><<"\n";
    }
    if (std::is_same_v<int&, decltype(val)>){
        std::cout <<"decltype(val) == int& "<< std::is_same_v<int&, decltype(val)><<"\n";
    }
    if (std::is_same_v<int&&, decltype(val)>){
        std::cout <<"decltype(val) == int&& "<< std::is_same_v<int&&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int&&, decltype(val)>){
        std::cout <<"decltype(val) == const int&& "<< std::is_same_v<const int&&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int&, decltype(val)>){
        std::cout <<"decltype(val) == const int& "<< std::is_same_v<const int&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int*&&, decltype(val)>){
        std::cout <<"decltype(val) == const int* && "<< std::is_same_v<const int* &&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int*, decltype(val)>){
        std::cout <<"decltype(val) == const int*  "<< std::is_same_v<const int* , decltype(val)><<"\n";
    }
    if (std::is_same_v< int*&&, decltype(val)>){
        std::cout <<"decltype(val) ==  int*&&  "<< std::is_same_v< int*&& , decltype(val)><<"\n";
    }
    if (std::is_same_v< int*, decltype(val)>){
        std::cout <<"decltype(val) ==  int*  "<< std::is_same_v< int* , decltype(val)><<"\n";
    }
       
}


template <typename  T>
void universal(T&& val){
    std::cout <<"universal\n";
    if (std::is_same_v<T, int>){
        std::cout <<"T == int "<< std::is_same_v<T, int><<"\n";
    }
    if (std::is_same_v<T,const int>){
        std::cout <<"T == const int "<< std::is_same_v<T,const int><<"\n";
    }
    if (std::is_same_v<T, int&>){
        std::cout <<"T == int& "<< std::is_same_v<T, int&><<"\n";
    }
    if (std::is_same_v<T, int&&>){
        std::cout <<"T == int&& "<< std::is_same_v<T, int&&><<"\n";
    }
    if (std::is_same_v<T,const int&>){
        std::cout <<"T == const int& "<< std::is_same_v<T,const int&><<"\n";
    }
    if (std::is_same_v<T,const int&&>){
        std::cout <<"T == const int&& "<< std::is_same_v<T,const int&&><<"\n";
    }
    if (std::is_same_v<T, int*>){
        std::cout <<"T == int* "<< std::is_same_v<T, int*><<"\n";
    }
    if (std::is_same_v<T,const int*>){
        std::cout <<"T ==const int* "<< std::is_same_v<T,const int*><<"\n";
    }



    if (std::is_same_v<int, decltype(val)>){
        std::cout <<"decltype(val) == int "<< std::is_same_v<int, decltype(val)><<"\n";
    }
    if (std::is_same_v<int&, decltype(val)>){
        std::cout <<"decltype(val) == int& "<< std::is_same_v<int&, decltype(val)><<"\n";
    }
    if (std::is_same_v<int&&, decltype(val)>){
        std::cout <<"decltype(val) == int&& "<< std::is_same_v<int&&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int&&, decltype(val)>){
        std::cout <<"decltype(val) == const int&& "<< std::is_same_v<const int&&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int&, decltype(val)>){
        std::cout <<"decltype(val) == const int& "<< std::is_same_v<const int&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int*&&, decltype(val)>){
        std::cout <<"decltype(val) == const int* && "<< std::is_same_v<const int* &&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int*, decltype(val)>){
        std::cout <<"decltype(val) == const int*  "<< std::is_same_v<const int* , decltype(val)><<"\n";
    }
    if (std::is_same_v< int*&&, decltype(val)>){
        std::cout <<"decltype(val) ==  int*&&  "<< std::is_same_v< int*&& , decltype(val)><<"\n";
    }

    if (std::is_same_v< int*, decltype(val)>){
        std::cout <<"decltype(val) ==  int*  "<< std::is_same_v< int* , decltype(val)><<"\n";
    }
    
       
}
template <typename  T>
void simpleref(T& val){
        std::cout <<"simple ref\n";
    if (std::is_same_v<T, int>){
        std::cout <<"T == int "<< std::is_same_v<T, int><<"\n";
    }
    if (std::is_same_v<T,const int>){
        std::cout <<"T == const int "<< std::is_same_v<T,const int><<"\n";
    }
    if (std::is_same_v<T, int&>){
        std::cout <<"T == int& "<< std::is_same_v<T, int&><<"\n";
    }
    if (std::is_same_v<T, int&&>){
        std::cout <<"T == int&& "<< std::is_same_v<T, int&&><<"\n";
    }
    if (std::is_same_v<T,const int&>){
        std::cout <<"T == const int& "<< std::is_same_v<T,const int&><<"\n";
    }
    if (std::is_same_v<T,const int&&>){
        std::cout <<"T == const int&& "<< std::is_same_v<T,const int&&><<"\n";
    }
    if (std::is_same_v<T, int*>){
        std::cout <<"T == int* "<< std::is_same_v<T, int*><<"\n";
    }
    if (std::is_same_v<T,const int*>){
        std::cout <<"T ==const int* "<< std::is_same_v<T,const int*><<"\n";
    }



    if (std::is_same_v<int, decltype(val)>){
        std::cout <<"decltype(val) == int "<< std::is_same_v<int, decltype(val)><<"\n";
    }
    if (std::is_same_v<int&, decltype(val)>){
        std::cout <<"decltype(val) == int& "<< std::is_same_v<int&, decltype(val)><<"\n";
    }
    if (std::is_same_v<int&&, decltype(val)>){
        std::cout <<"decltype(val) == int&& "<< std::is_same_v<int&&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int&&, decltype(val)>){
        std::cout <<"decltype(val) == const int&& "<< std::is_same_v<const int&&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int&, decltype(val)>){
        std::cout <<"decltype(val) == const int& "<< std::is_same_v<const int&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int*&&, decltype(val)>){
        std::cout <<"decltype(val) == const int* && "<< std::is_same_v<const int* &&, decltype(val)><<"\n";
    }
    if (std::is_same_v<const int*, decltype(val)>){
        std::cout <<"decltype(val) == const int*  "<< std::is_same_v<const int* , decltype(val)><<"\n";
    }
    if (std::is_same_v< int*&&, decltype(val)>){
        std::cout <<"decltype(val) ==  int*&&  "<< std::is_same_v< int*&& , decltype(val)><<"\n";
    }

    if (std::is_same_v< int*, decltype(val)>){
        std::cout <<"decltype(val) ==  int*  "<< std::is_same_v< int* , decltype(val)><<"\n";
    }
    
       
}



// custom move
template <typename T>
typename std::remove_reference<T>::type&& move(T&& val){
    return static_cast<typename std::remove_reference<T>::type&&>(val);
}


// forward r-value
template <typename T>
T&&  forward(typename std::remove_reference<T>::type&& val){
    static_assert(!std::is_lvalue_reference_v<T>,"lval ref");
    return static_cast<T&&>(val);
}

// forward l-value
template <typename T>
T&&  forward(typename std::remove_reference<T>::type& val){
    return static_cast<T&&>(val);
}


// test STL and custom forward
template <typename T>
void test_forw(T&& val){
    f(std::forward<T>(val));
    f(forward<T>(val));
}

//  in class template argument deduction, template parameter of a class template is never a forwarding reference
template <typename  T>
struct A{
    A(T&& val){
        std::cout << "rvalue constructor\n";
        universal(forward<T>(val));
    }

    A(const T& val){
        std::cout << "l-value constructor\n";
        universal(val);
    }

    // forwarding reference
    template<typename U>
    void run(U&& val){
        std::cout << "run(U&&)\n";
        universal(std::forward<U>(val));
    }

};



int main(){
   int a=1; // lvalue 
   std::cout <<std::boolalpha;
   std::cout <<"--------------\n";
   std::cout <<"template parameter of a class template A class1(a) \n";
   std::cout <<"lvalue \n";
   A class1(a);
   std::cout <<"rvalue class A class2(5) \n";
   A class2(5);
   
   std::cout <<"\n--------------\n";
   std::cout <<"template parameter of a method template \n";
   std::cout <<"\nrvalue method  class1.run(6);\n";
   class1.run(6);
   std::cout <<"\nl-value method  class1.run(a)\n";
   class1.run(a);
   
   std::cout <<"--------------\n";
   std::cout <<"\npointers universal(&a)\n";
   universal(&a);
   std::cout <<"\npointers simple(&a);\n";
   simple(&a);

   std::cout <<"--------------\n";
   std::cout << "universal(a);\n";
   universal(a);
   std::cout << "simple(a);\n";
   simple(a);

   std::cout <<"--------------\n";
   std::cout << "universal(1);\n";
   universal(42);
   std::cout << "simple(1);\n";
   simple(42);

   std::cout <<"--------------\n";
   std::cout <<"universal(move(a))\n";
   universal(move(a));
   std::cout <<"universal(std::move(a))\n";
   universal(std::move(a));

   std::cout <<"--------------\n";
   std::cout <<"const int\n";
   const int cint=1;
   universal(cint);
   simple(cint);
   simpleref(cint); 

    
  
};