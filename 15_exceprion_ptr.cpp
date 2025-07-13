// promiseFuture.cpp

#include <exception>
#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <utility>

void product(std::promise<int>&& intPromise, int a, int b){
  intPromise.set_value(a*b);
}

struct Div{

  void operator() (std::promise<int>&& intPromise, int a, int b) const {

    if (b==0){
        intPromise.set_exception(std::make_exception_ptr(std::invalid_argument("Division by zero")));
        return;
        }
    intPromise.set_value(a/b);        
  }
};

int main(){

  int a= 20;
  int b= 0;

  std::cout << std::endl;

  // define the promises
  std::promise<int> prodPromise;
  std::promise<int> divPromise;

  // get the futures
  std::future<int> prodResult= prodPromise.get_future();
  std::future<int> divResult= divPromise.get_future();

  // calculate the result in a separat thread
  std::thread prodThread(product,std::move(prodPromise),a,b);
  Div div;
  std::thread divThread(div,std::move(divPromise),a,b);

  // get the result
  try{
  std::cout << "20*0= " << prodResult.get() << std::endl;
  std::cout << "20/0= " << divResult.get() << std::endl;
  } catch (std::exception& ex){
    std::cerr<<ex.what()<<"\n";
  }

  prodThread.join();
  
  divThread.join();

  std::cout << std::endl;

}