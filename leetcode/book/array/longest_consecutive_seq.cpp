/**********************************************************************************************
 @description:
	Given an unsorted array of integers, find the length of the longest consecutive elements 
	sequence.
	For example, Given [100, 4, 200, 1, 3, 2], e longest consecutive elements sequence is 
	[1, 2, 3, 4]. Return its length: 4.
	Your algorithm should run in O(n) complexity.
/**********************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#if __cplusplus >= 201103L
#include <unordered_map>
#else
#include <map>
#endif
#if __cplusplus >= 201103L
int longest_consecutive(std::vector<int> const& nums)
{
	std::unordered_map<int, bool> used(nums.size());

	for(auto i: nums)
		used[i] =false;

	int longest = 0;

	for(auto i:nums)
	{
		if(used[i]) continue;
		int length = 1;

		used[i] = true;
		for(int j = i + 1; used.find(j) != used.end(); ++j)
		{
			used[j] = true;
			++length;
		}
		for(int j = i - 1; used.find(j) != used.end(); --j)
		{
			used[j] = true;
			++length;
		}
		longest = std::max(longest, length);
	}
	return longest;
}
#else
int longest_consecutive(std::vector<int> const& nums)
{
	std::map<int, bool> used;

	for(int i = 0; i < nums.size(); ++i)
		used[nums[i]] =false;

	int longest = 0;

	for(int i = 0; i < nums.size(); ++i)
	{
		if(used[nums[i]]) continue;
		int length = 1;

		used[nums[i]] = true;
		for(int j = nums[i] + 1; used.find(j) != used.end(); ++j)
		{
			used[j] = true;
			++length;
		}
		for(int j = nums[i]-1; used.find(j) != used.end(); --j)
		{
			used[j] = true;
			++length;
		}
		longest = std::max(longest, length);
	}
	return longest;
}
#endif

void test_longest_consecutive()
{
	int a[] = {100, 4, 200, 1, 3, 2, 7, 5, 8, 9, 10, 11, 12};
	std::vector<int> vec(a, a+ sizeof(a)/sizeof(int));
	std::cout << longest_consecutive(vec) << std::endl;
}
int main(int argc, char const *argv[])
{
	test_longest_consecutive();
	return 0;
}