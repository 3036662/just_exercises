// dotProduct.cpp

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <thread>
#include <vector>
#include <future>


//250005670515

static const long long NUM= 1000000000;

long long getDotProduct(std::vector<int>& v, std::vector<int>& w){
  return std::inner_product(v.begin(), v.end(), 
                             w.begin(), 
                             0LL);
}

long long getDotProductAsync(std::vector<int>& v, std::vector<int>& w){
 unsigned int procs=std::thread::hardware_concurrency();
 if (procs==0){procs=4;}
 uint64_t per_proc=v.size()/procs;
 std::vector<std::future<long long>> vec;
 vec.reserve(procs);
/// std::cout <<"Per proc:"<< per_proc<<"\n";
 auto it_start=v.begin();
 auto it_end=v.begin()+per_proc;
 auto it2_start=w.begin();
 for (unsigned int i=0;i<procs;++i){
    //std::cout<<"Distance for "<<i<<":" << std::distance(it_start,it_end)<<"\n";
    auto lambda=[it_start,it_end,it2_start](){
            return  std::inner_product(it_start,it_end,it2_start,0LL);
            };
    vec.emplace_back(        
         std::async(std::launch::async,lambda)
         );    
    it_start=it_end;
    it2_start+=per_proc;
    if (i==procs-2){
        it_end=v.end();     
    } else{        
        it_end=it_start+per_proc;    
    }
 }
 return std::accumulate(vec.begin(),vec.end(),0LL,[](long long int init,std::future<long long>& fut){ 
    long long res= fut.get();
   // std::cout << "Result:"<<res<<"\n";
    return init+res;
    });
}

long long getDotProductThreads(std::vector<int>& v, std::vector<int>& w){
 unsigned int procs=std::thread::hardware_concurrency();
 if (procs==0){procs=4;}
 uint64_t per_proc=v.size()/procs;
/// std::cout <<"Per proc:"<< per_proc<<"\n";
 auto it_start=v.begin();
 auto it_end=v.begin()+per_proc;
 auto it2_start=w.begin();
 std::vector<long long int> vec(procs,0);
 std::vector<std::thread> vec_threads;
 vec_threads.reserve(procs);
 auto lambda=[&vec](std::vector<int, std::allocator<int>>::iterator it_start,std::vector<int, std::allocator<int>>::iterator it_end,std::vector<int, std::allocator<int>>::iterator it2_start,size_t index){            
            long long res=0;
            for (auto it=it_start;it!=it_end;++it){
                res+=(*it)*(*it2_start);
                ++it2_start;
            }
            vec[index]=res;
            };
 for (unsigned int i=0;i<procs;++i){
    //std::cout<<"Distance for "<<i<<":" << std::distance(it_start,it_end)<<"\n";    
    vec_threads.emplace_back(std::thread(lambda,it_start,it_end,it2_start,i));
    it_start=it_end;
    it2_start+=per_proc;
    if (i==procs-2){
        it_end=v.end();     
    } else{        
        it_end=it_start+per_proc;    
    }
 }
 std::for_each(vec_threads.begin(),vec_threads.end(),[](std::thread& th){
    th.join();
 });
 long long int res=0;
 for (auto it=vec.begin();it!=vec.end();++it){
    res+=*it;
 }
 return res;
}


long long getDotProduct4Async(std::vector<int>& v, std::vector<int>& w){

  auto future1= std::async([&]{return std::inner_product(&v[0], &v[v.size()/4], &w[0], 0LL);});
  auto future2= std::async([&]{return std::inner_product(&v[v.size()/4], &v[v.size()/2], &w[v.size()/4], 0LL);});
  auto future3= std::async([&]{return std::inner_product(&v[v.size()/2], &v[v.size()*3/4], &w[v.size()/2], 0LL);});
  auto future4= std::async([&]{return std::inner_product(&v[v.size()*3/4], &v[v.size()], &w[v.size()*3/4], 0LL);});

  return future1.get() + future2.get() + future3.get() + future4.get();
}

int main(){

  std::cout << std::endl;

  // get NUM random numbers from 0 .. 100
  std::random_device seed;

  // generator
  std::mt19937 engine(seed());

  // distribution
  std::uniform_int_distribution<int> dist(0, 100);

  // fill the vectors
  std::vector<int> v,  w;
  v.reserve(NUM);
  w.reserve(NUM);
  for (long long i=0; i< NUM; ++i){
    v.push_back(dist(engine));
    w.push_back(dist(engine));
  }

  // measure the execution time
  std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
  std::cout << "getDotProduct(v, w): " << getDotProduct(v, w) << std::endl;
  std::chrono::duration<double> dur  = std::chrono::system_clock::now() - start;
  std::cout << "Sequential Execution: "<< dur.count() << std::endl;

   start =std::chrono::system_clock::now();
   std::cout << "getDotProduct(v, w): " << getDotProductAsync(v, w) << std::endl;
   dur  = std::chrono::system_clock::now() - start;
   std::cout << "Parallel Execution Async: "<< dur.count() << std::endl;


  start =std::chrono::system_clock::now();
  std::cout << "getDotProduct(v, w): " << getDotProductThreads(v, w) << std::endl;
  dur  = std::chrono::system_clock::now() - start;
  std::cout << "Parallel Execution Threads: "<< dur.count() << std::endl;

   start =std::chrono::system_clock::now();
   std::cout << "getDotProduct(v, w): " << getDotProduct4Async(v, w) << std::endl;
   dur  = std::chrono::system_clock::now() - start;
   std::cout << "Parallel Execution 4 Async: "<< dur.count() << std::endl;

  std::cout << std::endl;

}