// 描述
// Given an array S of n integers, are there elements a; b; c, and d in S such that a+b+c+d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Note:2.1 数组 13
// • Elements in a quadruplet (a; b; c; d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// • e solution set must not contain duplicate quadruplets.
// For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
// A solution set is:
// (-1, 0, 0, 1)
// (-2, -1, 1, 2)
// (-2, 0, 0, 2)
// 使用C++11的feature进行实现
// template <class BidirectionalIterator>
// BidirectionalIterator prev (BidirectionalIterator it,
//      typename iterator_traits<BidirectionalIterator>::difference_type n = 1);
//
// template <class ForwardIterator>
//   ForwardIterator next (ForwardIterator it,
//        typename iterator_traits<ForwardIterator>::difference_type n = 1);
#include <algorithm>
using std::sort;
using std::binary_search;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <iterator>
using std::prev;
using std::next;


vector<vector<int>> fourSum(vector<int>& num, int target)
{
	vector< vector<int> > result;
	if(num.size() < 4) return result;
	sort(num.begin(), num.end());

	auto last = num.end();
	for (auto a = num.begin(); a < prev(last, 3); a = upper_bound(a, prev(last, 3), *a))
	{
		for(auto b = next(a);b < prev(last, 2); b = upper_bound(b, prev(last, 2), *b))
		{
			for(auto c = next(b); c < prev(last); c = upper_bound(c, prev(last), *c))
			{
				const int d = target - *a - *b - *c;
				if(binary_search(next(c), last, d))
					result.push_back(vector<int>{*a, *b, *c, d});
			}
		}
	}
}

void test_foursum()
{
	int a[] = {1, 0, -1, 0, -2, 2};

	vector<int> num(a, a + 6);
	vector<vector<int>> result = fourSum(num, 0);
	for(auto a: result)
	{
		std::cout << "{";
		for(auto b: a)
		{
			std::cout << b << " ";
		}
		std::cout << "}" << std::endl;
	}
}
int main(int argc, char const *argv[])
{
	test_foursum();
	return 0;
}