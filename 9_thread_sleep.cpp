#include <iostream>
#include <thread>
#include <chrono>

int main() {
  // your code goes here
  for (int i=10;i>=0;--i){
    std::cout <<i<<"\n";
    std::this_thread::sleep_for( std::chrono::seconds(1) );
  }
 
  return 0;
}