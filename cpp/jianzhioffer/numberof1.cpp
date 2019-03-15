#include <bitset>
#include <iostream>

using namespace std;

class Solution
{
 public:
   int NumberOf1(int n)
   {
      // bitset<32> bit(n);
      //  return bit.count();
      int count = 0;
      while (n)
      {
         count++;
         n = n & (n - 1);
      }
      return count;
   }
   int NumberOf1_2(int n)
   {
      // bitset<32> bit(n);
      //  return bit.count();
      int count = 0;
      while (n)
      {
         if(n^(n-1))
            count++;
         n = n & (n - 1);
      }
      return count;
   }
   int Numberof1(int n) { 
      bitset<32> bt(n); 
      return bt.count();
    }
};
ostream& bin(ostream& os, int i)
{
   os << bitset<32>(i);
   return os;
}
int main(int argc, char const *argv[])
{
   Solution solve;
   for(int i = 0xFFFFFFF0; i < 0xFFFFFFFF; i++)
      bin(std::cout, i)<<" : " << solve.NumberOf1(i)  <<" " <<solve.NumberOf1_2(i) << std::endl;
   return 0;
}