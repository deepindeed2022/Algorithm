#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
int findMin(vector<int>& nums) 
{
    int i = 0;
    int j = nums.size() -1;
    int mid;
    while(i < j)
    {
        while(i < j && (nums[i] == nums[i+1])) ++i;
        while(i < j && (nums[j-1] == nums[j])) --j;
        // because the two element haven't order, only the element num > 3 we can 
        // get one side is ordered.
        if(i + 1 == j) return std::min(nums[i], nums[j]);
        mid = (i+j)/2;
        if(nums[i] < nums[j])
            return nums[i];
        else
        {
            if(nums[mid] > nums[j])
            {
                i = mid + 1;
            }
            else 
            if(nums[mid] < nums[i])
            {
                j = mid;
            }
        }
    }
    return nums[i];//because if the test case is [2 3 1],  when a loop , the i = j = 2; the loop will be end
}

void test_findMin()
{
    int a[] = {4, 5,5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 7, 7, 0, 1, 2};
    std::vector<int> vec(a, a + sizeof(a)/sizeof(int));
    assert(findMin(vec) == 0);
    std::vector<int> vec2(3, 0);
    vec2[0] = 2;
    vec2[1] = 3;
    vec2[2] = 1;
    assert(findMin(vec2) == 1);
}   
int main(int argc, char const *argv[])
{
    test_findMin();
    return 0;
}