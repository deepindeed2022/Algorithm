// 描述
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
// target. Return the sum of the three integers. You may assume that each input would have exactly one
// solution.
// For example, given array S = {-1 2 1 -4}, and target = 1.
// e sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int threeSumClosest(std::vector<int>& nums, int target) 
{
    // Note: make sure to think the boundary parameter
	int result = 0;
	int min_gap = INT_MAX;

    std::sort(nums.begin(), nums.end());
    std::vector<int>::iterator last = nums.end();

    for(std::vector<int>::iterator  a = nums.begin(); a < prev(last, 2); 
        a = upper_bound(a, prev(last, 2), *a))
    {
         auto b = next(a);
         auto c = prev(nums.end());
         while(b < c)
         {
         	const int sum = *a + *b + *c;
         	const int gap = abs(sum - target);
         	if(gap < min_gap)
         	{
         		result = sum;
         		min_gap = gap;
         	}
         	if(sum < target) ++b;
         	else --c;
         }
    }
    return result;
}
void test_threeSum()
{
    int a[]= {-1, 2, 1, -4};
    typedef std::vector<std::vector<int> > resType;
    std::vector<int> vec(a, a + sizeof(a)/sizeof(int));
    int result = threeSumClosest(vec, 1);
    std::cout << result << std::endl;

}
int main(int argc, char const *argv[])
{
    test_threeSum();
    return 0;
}