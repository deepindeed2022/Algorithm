#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
    	// Only the first bit is 1 else return false
       	if (n & (n - 1) != 0) return false;
       	if (0x55555555 & n) return true;
       	return false;
    }
};
int main(int argc, char const *argv[])
{
  Solution solve;
  std::cout << solve.isPowerOfFour(12);
  cout<< solve.isPowerOfFour(16);
  return 0;
}