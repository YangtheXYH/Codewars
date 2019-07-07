//https://www.codewars.com/kata/playing-with-digits/train/cpp

#include <string>
#include <cmath>
class DigPow
{
public:
  static int digPow(int n, int p);
};

int DigPow::digPow(int n,int p)
{
    std::string test=std::to_string(n);
    float sum=0;
    for(int i=0;i<test.size();i++)
    {
        sum+=std::pow(test[i]-'0',(p+i));
    }
    /*for(int k=1;k<=(sum/std::stoi(test));k++) //我都不知道我当时在想什么
      if(std::stoi(test)*k==sum)
          return k;*/
    float k=sum/std::stoi(test);
    int flag=(int)k;
    if(k==(float)flag)
      return flag;
    else
      return -1;
}

//Best Practices
/*
#include <cmath>
using namespace std;
class DigPow
{
public:
  static int digPow(int n, int p){
   long long sum=0;
   for(char digit : to_string(n)){
     sum+=pow(digit-'0',p++);
   }
   return (sum/n)*n==sum ? sum/n : -1; //就是这里优化了下
  }
};
*/
