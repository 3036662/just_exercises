#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

// ping pong, two threads setting true and false with one function and one conditional variable

constexpr int kMaxIter=100;

void SendData(std::mutex& mtx,std::condition_variable& cond,bool& data,bool new_data){
    static int counter=0;
    while(counter<kMaxIter){    
        std::unique_lock<std::mutex> lock(mtx);        
        cond.wait(lock,[new_data,&data](){return data!=new_data;});       
        if (counter<kMaxIter){
            data=new_data;
            std::cout<< std::this_thread::get_id()<< (new_data ? " ping":" pong")<<"\n";
            ++counter;
            cond.notify_one();        
        }
    }    
    std::cout << std::this_thread::get_id()<<" counter = "<<counter<<"\n";
}

int main(){
    std::mutex mtx;
    std:std::condition_variable cond;
    bool data=false;    
    std::thread th1(SendData,std::ref(mtx),std::ref(cond),std::ref(data),true);
    std::thread th2(SendData,std::ref(mtx),std::ref(cond),std::ref(data),false);

    th1.join();
    th2.join();


}