#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>
#include <cstring>
#include <string>
#include <utility>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        string rev = to_string(x);
        //Check for negatigves
        if(rev[0] == '-')
            sign = -1;
        std::reverse(rev.begin(),rev.end());
        //long takes care of overflow
        long new_int = stol(rev);
        if (new_int >= INT_MAX || new_int <= INT_MIN)
            return 0;
        return new_int * sign;  
    }
    bool isMatch(string s, string p) {
        
    }
};
void test_intreverse()
{
  Solution solve;
  int num = 123;
  assert(321 == solve.reverse(num));
}

int main(int argc, char const *argv[])
{
  test_intreverse();
  return 0;
}