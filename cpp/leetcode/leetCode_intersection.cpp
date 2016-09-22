#include <vector>
#include <set>
#include <iterator>
#include <cassert>
#include <iostream>
using std::vector;
using std::set;
using std::cout;
using std::endl;
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	    set<int> s(nums1.begin(), nums1.end());
	    vector<int> out;
	    for (std::vector<int>::iterator i = nums2.begin(); i != nums2.end(); ++i)
		    if (s.erase(*i))
		            out.push_back(*i);
	
	    return out;
	}
};

///////////////////////////////////////////
//
// TEST_CODE MAIN FUNCTION TO CALL
//
///////////////////////////////////////////

int main(int argc, char const *argv[])
{
  Solution solve;
  int a[12] = {1,2,3,4,5,6,7,8,8,8,8,555};
  std::vector<int> vec1(a, a+12);
  int b[6] = {1,2,3,4,5,333};
  std::vector<int> v(b,b+6);
  std::cout << "START TEST:\n";
  std::vector<int> result = solve.intersection(vec1, v);
  for (std::vector<int>::iterator i = result.begin(); i != result.end(); ++i)
  {
  	std::cout<< *i<< " ";
  }
  

  std::cout << "TEST SUCCESS!\n";
  return 0;
}