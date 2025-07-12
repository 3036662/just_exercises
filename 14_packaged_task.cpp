// packagedTask.cpp

#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>
#include <future>
#include <iostream>
#include <thread>
#include <deque>
#include <vector>

class SumUp{
  public:
    int operator()(int beg, int end){
      long long int sum{0};
      for (int i= beg; i < end; ++i ) sum += i;
      return sum;
    }
};

int main(){

  std::cout << std::endl;
  unsigned int procs=std::thread::hardware_concurrency();
  if (procs==0){
    procs=4;
  }
  std::deque< std::packaged_task<int(int, int)> > allTasks;
  for (size_t i=0;i<procs;++i){
    allTasks.emplace_back(SumUp());
  }
  std::vector<std::future<int>> futures;
  std::transform(allTasks.begin(),allTasks.end(),std::back_inserter(futures),[]( auto& task){
    return task.get_future();
  });

  int begin{1};
  int increment=10000/procs;
  int end= begin+increment;
  
  std::cout <<"Futures size:"<<futures.size()<<"\n";
  std::cout << "Increment:"<<increment<<"\n";
  
  // execute each task in a separate thread
  while ( ! allTasks.empty() ){
    std::packaged_task<int(int, int)> myTask= std::move(allTasks.front());
    allTasks.pop_front();
    std::thread sumThread(std::move(myTask), begin, end);
    begin= end;
    end += increment;
    sumThread.detach();
  }

  // get the results
  long long sum=std::accumulate(futures.begin(),futures.end(),0LL,[](const int init,std::future<int>& fut){
    return init+fut.get();
  });
  std::cout << begin <<" end"<<end<<"\n";
  if (begin<10001){
    sum+=SumUp()(begin,10001);
  }
  

  std::cout << "sum of 0 .. 10000 = " << sum << std::endl;

  std::cout << std::endl;

}