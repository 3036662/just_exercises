// spinLockSleep.cpp

#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>

class Spinlock{
  std::atomic_flag flag;
  std::mutex a;
public:
  Spinlock(): flag ATOMIC_FLAG_INIT{}

  void lock(){
    while( flag.test_and_set() );
  }

  void unlock(){
    flag.clear();
  }
};

Spinlock spin;

void workOnResource(){
  spin.lock();
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  spin.unlock();
  std::cout << "Work done" << std::endl;
}


int main(){

  std::thread t(workOnResource);
  std::thread t2(workOnResource);

  t.join();
  t2.join();

}