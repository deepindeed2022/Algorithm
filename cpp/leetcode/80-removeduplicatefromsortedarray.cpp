//////////////////////////////////////////////////////////////////////////////////////////
// Follow up for "Remove Duplicates":                                                   //
// What if duplicates are allowed at most twice?                                        //
//                                                                                      //    
// For example,                                                                         //            
// Given sorted array nums = [1,1,1,2,2,3],                                             //            
//                                                                                      //
// Your function should return length = 5, with the first five elements of nums         //
// being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.      //
//////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 1) return nums.size();    
    int cur = nums[0];
    bool flag = false;
    int count  = 1;
    for(vector<int>::iterator it = nums.begin()+1; it != nums.end();)
    {
        if(*it == cur)
        {
            if(++count > 2)
            {
                it = nums.erase(it);
                --count;
            }
            else
            {
                ++count;
                ++it;
            }
        }
        else
        {   
            cur = *it;
            count = 1;
            ++it;
        }
    }
    return nums.size();
}
int removeDuplicates_1(vector<int>& nums)
{
    int i = 0;
    for(int n: nums)
    {
        if(i < 2 || n > nums[i-2])
        {
            nums[i] = n;
            ++i;
        }
    }
    return i;
}
template <int K>
int removeDuplicatesK(std::vector<int>& nums)
{
    int i = 0;
    for(int n: nums)
    {
        if(i < K || n > nums[i-K])
        {
            nums[i++] = n;
        }
    }
    return i;
}
void test_removeDuplicates()
{
    int a[] = {1, 1, 2, 2, 2, 3};
    vector<int> input(a, a+6);
    assert(5== removeDuplicates(input));
    assert(5== removeDuplicates_1(input));

    int b[] = {1,1,1,1,2,2,2,2,2,3,3,3,4,4};
    vector<int> nums(b, b+14);
    assert(13 == removeDuplicatesK<4>(nums));
}
int main(int argc, char const *argv[])
{
    test_removeDuplicates();
    return 0;
}