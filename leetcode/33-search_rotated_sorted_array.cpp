// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Subscribe to see which companies asked this question.
//
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
int search(std::vector<int>& nums, int target)
{
    int i = 0;
    int j = nums.size();
    int mid;
    while(i != j)
    {
        mid = (i + j)>>1;
        if(nums[mid] == target) 
            return mid;
        if(nums[mid] > nums[i])
        {
            if(nums[i] <= target && target < nums[mid])
                j = mid;
            else
                i = mid + 1;
        }
        else 
        {
            if(nums[mid] <= target && target <= nums[j -1])
                i = mid +1;
            else
                j = mid;

        }
    }
        return -1;
}
void test_search()
{
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    std::vector<int> vec(a, a+7);
    assert(search(vec, 7) == 3);
    assert(search(vec, 0) == 4);
    assert(search(vec, 8) == -1);
    int b[] = {1};
    std::vector<int> vec2(b, b+1);
    assert(search(vec2, 0) == -1);

}
int main(int argc, char const *argv[])
{
    test_search();
    return 0;
}