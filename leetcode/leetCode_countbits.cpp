#include <iostream>
#include <vector>
#include <iterator>
using std::vector;
using std::iterator;
using std::cout;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> r;
        r.push_back(0);
        for (int i = 1;i <= num; i++)
        {
        	// Because for an integer i, when i/2 equals to the bit representation 
        	// of i shift right for one bit. So it's r[i/2]. And we just need to 
        	// add i%2 which is the most right hand side of the bit set.
            int x = r[i/2]+ (i%2);
            r.push_back(x);
        }
        return r;
    }
};


int main(int argc, char const *argv[])
{
  Solution solve;
  int num = 15;
  vector<int> r  = solve.countBits(num);
  for (std::vector<int>::iterator i = r.begin(); i != r.end(); ++i)
  {
  	std::cout<<(*i)<<" ";
  }
  
  return 0;
}