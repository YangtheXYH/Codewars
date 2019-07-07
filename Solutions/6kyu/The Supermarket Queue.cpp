//https://www.codewars.com/kata/the-supermarket-queue/train/cpp
//我的代码无法通过全部测试用例，因而这里给出的是两个能通过的程序

long queueTime(std::vector<int> customers,int n)
{
  std::vector<long> queues(n, 0);
  
  for (int i : customers)
    *std::min_element(queues.begin(), queues.end()) += i;
    
  return *std::max_element(queues.cbegin(), queues.cend());
}

/*
#include <queue>
#include <functional>
long queueTime(std::vector<int> customers,int n)
{
  std::priority_queue<int, std::vector<int>, std::greater<int>> time;
  for (auto &customer: customers) 
  {
    if (time.size() < n) 
    {
      time.push(customer);
    } 
    else 
    {
      auto top = time.top();
      time.pop();
      time.push(top + customer);
    }
  }
  int res;
  while (!time.empty()) 
  {
    res = time.top();
    time.pop();
  }
  return res;
}
*/
