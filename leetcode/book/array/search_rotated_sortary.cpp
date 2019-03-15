/**
 * @FILE: /array/search_rotated_sortary.cpp
 * @DESCRIPTION: 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * @AUTHOR: wenlong.cao
 * @CREATE: 2016-11-23
 **/
#include <iostream>
#include <vector>
using namespace std;
#include <cassert>
// every iteration, delete the part of sorted
int search(int A[], int n, int target) 
{
    int first = 0, last = n;
    while (first != last) 
    {
        const int mid = (first + last) / 2;

        if (A[mid] == target)
            return mid;

        if (A[first] <= A[mid]) 
        {
            if (A[first] <= target && target < A[mid])
                last = mid;
            else // if target cannot meeting previous condition, means the target may occur in another part
                first = mid + 1;
        } else 
        {
            if (A[mid] < target && target <= A[last-1])
                first = mid + 1;
            else
                last = mid;
        }
    }
    return -1;
}
void test_search_rotated_sortary()
{
    int A[] = {4,5,6,7,8,9,0,1,2};
    assert( -1 == search(A,9,3));
    assert( 8 == search(A,9,2));
}
int main(int argc, char const *argv[])
{
   test_search_rotated_sortary();
    return 0;
}