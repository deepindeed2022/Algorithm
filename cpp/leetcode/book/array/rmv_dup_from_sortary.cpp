
/**
 * @file: /array/rmv_dup_from_sortary.cpp
 * @description:
 * Given a sorted array, remove the duplicates in place such that each element appear only
 * once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example, Given input array A = [1,1,2],
 * Your  function should return length = 2, and A is now [1,2]
 * @author: wenlong.cao
 * @create: 2016-11-23
 * @notice: using C++11 features, the function should be compiled using -std=C++11
 **/
#include <algorithm>
#include <vector>
using std::vector;
#include <ctime>
#include <iostream>
#include "debug.h"
using namespace TEST;
// bool is_sorted_array(std::vector<int>& ary)
// {
//     return std::is_sorted(ary.begin(), ary.end());
// }

int remove_duplicates_1(std::vector<int> v)
{
    if(v.size() == 0) return 0;

    int index = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[index] != v[i])
            v[++index] = v[i];
    }
    return index + 1;
}
int remove_duplicates_2(std::vector<int> v)
{
    return std::distance(v.begin(), std::unique(v.begin(), v.end()));
}

#define RANDOM_MAX 20
void test_remove_duplicates()
{
    // Generate test case data
    srand(0);
    const int size = 30;
    std::vector<int> a(size, 0);
    for (int i = 0; i < size; ++i)
    {
        a[i] = rand() % RANDOM_MAX;
    }
    std::sort(a.begin(),a.end());
    assert(std::is_sorted(a.begin(), a.end()));

    // test 
    assert(15 == remove_duplicates_1(a));
    assert(15 == remove_duplicates_2(a));
}
int main(int argc, char const *argv[])
{
    test_remove_duplicates();

    return 0;
}