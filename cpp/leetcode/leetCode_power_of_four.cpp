#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
    	  // Only the first bit is 1 else return false
       	if(n < 0) return false;
        if ((n&(n - 1)) != 0) return false;// power of 2
       	if (0x55555555 & n) return true;
       	return false;
    }
};
int main(int argc, char const *argv[])
{
  Solution solve;
  assert(!solve.isPowerOfFour(-242));
  assert(!solve.isPowerOfFour(6));
  assert(solve.isPowerOfFour(16));
  int n = 6;
  int a = (n&(n - 1) != 0);
  int b = ((n&(n-1)) != 0);
  std::cout << a << " " << b << std::endl;
  std::cout << ((n&(n-1)) != 0) << std::endl;
  return 0;
}

// != 优先级比& 高