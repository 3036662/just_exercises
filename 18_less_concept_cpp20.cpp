#include <ios>
#include <iostream>
#include <type_traits>

//Object-oriented with dynamic polymorphism.

class RelationalDynamic{
public:    
    virtual bool operator <(const RelationalDynamic& other) const=0;
};

bool operator > (const RelationalDynamic& a,const RelationalDynamic&b ){
    return b<a;
}

bool operator ==(const RelationalDynamic& a,const RelationalDynamic&b){
    return !(a<b || b<a);
}

bool operator !=(const RelationalDynamic&a,const RelationalDynamic&b){
    return a<b || b>a;
}

bool operator <=(const RelationalDynamic&a,const RelationalDynamic&b){
    return a<b || a==b;
}

bool operator >=(const RelationalDynamic &a,const RelationalDynamic&b){
    return b<a || a==b;
}


class ObjectDyn :public RelationalDynamic{
public:
  explicit ObjectDyn(int val):val_(val){};
  bool operator<(const RelationalDynamic& other) const override  {
    const ObjectDyn* p_other=dynamic_cast<const ObjectDyn*>(&other);  
    if (p_other!=nullptr){
        return val_<p_other->val_;
    }
    return false;
  }  
private:
  int val_=0;
};



template <typename T,typename = std::enable_if_t<std::is_convertible_v<decltype(std::declval<T>()<std::declval<T>()), bool>>>
bool less(const T& a,const T&b ){return a<b;}

struct NonComparable{};

#if __cplusplus >= 202002L
template <typename T>
concept Comparable= requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

template <Comparable T>
bool ConceptLess(const T&a,const T&b){return a<b;}
#endif

int main(){
    const ObjectDyn dyn1(1);
    const ObjectDyn dyn2(2);
    std::cout <<std::boolalpha;
    std::cout <<"dyn1 == dyn2: "<< (dyn1==dyn2) <<"\n";
    std::cout <<"dyn1 < dyn2: "<< (dyn1<dyn2) <<"\n";
    std::cout <<"dyn1 <= dyn2: "<< (dyn1<=dyn2) <<"\n";
    std::cout <<"dyn1 > dyn2: "<< (dyn1>dyn2) <<"\n";
    std::cout <<"dyn1 >= dyn2: "<< (dyn1>=dyn2) <<"\n";

    std::cout <<"less(dyn1,dyn2) :"<< less(dyn1,dyn2)<<"\n";
    std::cout <<"Less::less(dyn1,dyn2) :"<< less(dyn1,dyn2)<<"\n";

   // std::cout <<"less(dyn1,'aaa') :"<<less(NonComparable{},NonComparable{})<<"\n"; // ERROR
   #if __cplusplus >= 202002L
   std::cout <<"ConceptLess(1,2):"<<ConceptLess(1,2)<<"\n";
   std::cout <<"ConceptLess(dyn1,dyn2):"<<ConceptLess(dyn1,dyn2)<<"\n";
   // std::cout <<"ConceptLess(dyn1,'aaa') :"<<ConceptLess(NonComparable{},NonComparable{})<<"\n"; // ERROR
   #endif
};