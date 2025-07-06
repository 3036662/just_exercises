#include <iostream>
#include <mutex>
#include <thread>

class MySingleton{

  private:
    static MySingleton* instance;
    static std::once_flag once_flag;

    MySingleton()= default;
    ~MySingleton()= default;

  public:
    MySingleton(const MySingleton&)= delete;
    MySingleton& operator=(const MySingleton&)= delete;

    static MySingleton* getInstance(){
      std::call_once(once_flag, [](){instance=new MySingleton();});      
      return instance;
    }
};

MySingleton* MySingleton::instance= nullptr;
std::once_flag MySingleton::once_flag;

int main(){

  std::cout << std::endl;

  std::thread thread1([](){ std::cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << std::endl;});
  std::thread thread2([](){ std::cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << std::endl;});

  thread1.join();
  thread2.join();
  std::cout << std::endl;

}