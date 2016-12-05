/**********************************************************************************************
Find the contiguous subarray within an array (containing at least one number) which has the 
largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous subarray [4,−1,2,1] has
the largest sum = 6
/**********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

int get_max_subarray(std::vector<int>& vec)
{
    int size = vec.size();
    std::vector<int> max_subarray(size, 0);
    max_subarray[0] =  vec[0];
    for(int i = 1; i < size; ++i)
    {
        max_subarray[i] = std::max(vec[i], max_subarray[i-1] + vec[i]);
    }
    return (*max_element(max_subarray.begin(), max_subarray.end()));
}
int main(int argc, char const *argv[])
{
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> vec(a, a+9);
    std::cout << get_max_subarray(vec) <<std::endl;
    return 0;
}