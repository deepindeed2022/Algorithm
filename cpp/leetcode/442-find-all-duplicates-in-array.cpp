// https://leetcode.com/problems/find-all-duplicates-in-an-array/#/description
// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array),
// some elements appear twice and others appear once.
// Find all the elements that appear twice in this array.
// Could you do it without extra space and in O(n) runtime?
//
// Example:
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [2,3]
// 分析：
//  Firstly, we put each element x in nums[x - 1]. Since x ranges from 1 to N, 
// then x - 1 ranges from 0 to N - 1, it won't exceed the bound of the array.
// Secondly, we check through the array. If a number x doesn't present in nums[x - 1], then x is absent.

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    int i = 0;
    while(i < nums.size())
    {
    	if(nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
    	else ++i;
    }
    for(int i = 0; i < nums.size(); ++i)
    {
    	if(nums[i] != i + 1) res.push_back(nums[i]);
    }
    return res;
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,5,4,1};
	vector<int> aa(a, a+5);
	for(auto i : findDuplicates(aa))
	{
		std::cout << i << std::endl;
	}	
	for(auto i : aa)
	{
		std::cout << i << " ";
	}
	return 0;
}
