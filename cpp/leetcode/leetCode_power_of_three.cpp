#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
       return n > 0 && ((int)pow(3, (int)(log(INT_MAX)/log(3))) % n == 0);
    }
};
int main(int argc, char const *argv[])
{
  Solution solve;
  std::cout << solve.isPowerOfThree(100);
  cout<< solve.isPowerOfThree(81);
  return 0;
}