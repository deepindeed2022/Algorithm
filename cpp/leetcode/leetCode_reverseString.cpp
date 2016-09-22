#include <iostream>
#include <string>
using std::cout;
using std::string;
class Solution {
public:
    string reverseString(string s) {
        int r = s.size() -1;
        int l = 0;
        while(r > l)
        	std::swap(s[l++],s[r--]);
        return s;
    }
};

int main(int argc, char const *argv[])
{
  Solution solve;
  string s("hello");
  std::cout << solve.reverseString(s);
  
  return 0;
}