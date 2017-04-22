/**********************************************************************************************
@description:
 Given an array S of n integers, are there elements a; b; c in S such that a+ b+ c = 0? Find all unique
triplets in the array which gives the sum of zero.

@Note:
• Elements in a triplet (a; b; c) must be in non-descending order. (ie, a ≤ b ≤ c)
• e solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4}.
A solution set is:
(-1, 0, 1)
(-1, -1, 2)
/**********************************************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

std::vector<std::vector<int> > threeSum(std::vector<int>& nums) 
{
    // Note: make sure to think the boundary parameter
    std::vector<std::vector<int> > finalResult;
    if(nums.size() == 0)
        return finalResult;
    
    std::vector<int> result(3, 0);
    std::sort(nums.begin(), nums.end());
    const int target = 0;
    std::vector<int>::iterator last = nums.end();

    for(std::vector<int>::iterator  a = nums.begin(); a < prev(last, 2); 
        a = upper_bound(a, prev(last, 2), *a))
    {
         for(std::vector<int>::iterator b = next(a); b < prev(last); 
            b = upper_bound(b, prev(last), *b))
         {
            const int c = target - *a - *b;
            if(binary_search(next(b), last, c))
            {
                result[0] = *a;
                result[1] = *b;
                result[2] = c;
                finalResult.push_back(result);
            }
         }
    }
    return finalResult;
}
void test_threeSum()
{
    int a[]= {};
    typedef std::vector<std::vector<int> > resType;
    std::vector<int> vec(a, a + sizeof(a)/sizeof(int));
    resType result = threeSum(vec);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[0].size(); ++j)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

}
int main(int argc, char const *argv[])
{
    test_threeSum();
    return 0;
}