/**********************************************************************************************
 @description:
 FIXME:
C++11 Features
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
    
    std::vector<int> result(3,0);
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