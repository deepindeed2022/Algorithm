// A message containing leers from A-Z is being encoded to numbers using the
// following mapping:
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of
// ways to decode it.
// For example, Given encoded message "12", it could be decoded as "AB" (1 2) or
// "L" (12).
// e number of ways decoding "12" is 2.
// 分析：
// 类似上楼梯的：上一个楼梯和两个楼梯，一共有多少中走法。 不过这里要考虑可不可以走两步的问题。
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int numDecodings(const string &s)
{
   if (s.empty() || s[0] == '0')
      return 0;
   int prev = 0;
   int cur  = 1;
   for (size_t i = 1; i <= s.size(); ++i)
   {
      if (s[i - 1] == '0') cur = 0;
      if (i < 2 || !(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
         prev = 0;
      int tmp = cur;
      cur     = prev + cur;
      prev    = tmp;
   }
   return cur;
}
int main(int argc, char const *argv[])
{
   string s("123");
   std::cout << numDecodings(s) << std::endl;
   return 0;
}