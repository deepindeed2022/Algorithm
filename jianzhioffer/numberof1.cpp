#include <bitset>
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
   int Numberof1(int n) { 
      bitset<32> bt(n); 
      return bt.count();
    }
};