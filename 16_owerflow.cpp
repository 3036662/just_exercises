#include <cstdint>
#include <iostream>
#include <cmath>
#include <limits>

long double z = 1.189731495357231765L;

int main(){
    double inf=INFINITY;
    std::cout << "Infinity:"<<inf<<"\n\n";
    int max_i=std::numeric_limits<int>::max();
    ++max_i;
    int min_i=std::numeric_limits<int>::min();
    --min_i;
    std::cout <<"max int +1 ="<<max_i<<"\n";
    std::cout <<"min int -1 ="<<min_i<<"\n\n";
    unsigned int max_ui=std::numeric_limits<unsigned int>::max();
    ++max_ui;
    unsigned int min_ui=std::numeric_limits<unsigned int>::min();
    --min_ui;
    std::cout <<"max unsigned int +1 ="<<max_ui<<"\n";
    std::cout <<"min unsigned int -1 ="<<min_ui<<"\n\n";
    double d=std::numeric_limits<double>::max();
    d*=2;
    double md=std::numeric_limits<double>::min();
    std::cout <<"double min  = "<<md<<"\n";
    md*=0.01;
    std::cout <<"double min * 0.01 = "<<md<<"\n";
    std::cout <<"double max * 2 = "<<d<<"\n\n";
    
}