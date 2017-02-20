#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// int removeElement(vector<int>& nums, int val) {
//     int count = 0;
//     for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
//     {
//         if(val == *it) 
//         {
//             std::swap(*(nums.begin()+count), *it);
//             count++;
//         }
//     }
//     nums.erase(nums.begin(), nums.begin() + count);
//     return nums.size();
// }

int removeElement(vector<int>& nums, int val)
{
    int count = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] != val)
        {
            nums[i - count] = nums[i];
        }
        else
        {
            count++;
        }
    }
    return nums.size() - count;
}
void test_removeElement()
{
    int a[] = {1, 2, 3, 1 ,2 ,3 ,12 ,2 ,3, 3};
    std::vector<int> nums(a, a+10);
    std::cout << removeElement(nums, 3) << std::endl;
}
int main(int argc, char const *argv[])
{
    test_removeElement();
    return 0;
}