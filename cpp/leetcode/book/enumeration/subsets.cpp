// Given a set of distinct integers, S, return all possible subsets.
// Note:
// • Elements in a subset must be in non-descending order.
// • e solution set must not contain duplicate subsets.
// For example, If S = [1,2,3], a solution is:
// [
// [3],
// [1],
// [2],
// [1,2,3],
// [1,3],
// [2,3],
// [1,2],
// []
// ]

#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
#include <iostream>
using std::endl;
using std::cout;
class Subsets_Recursion
{
private:
	void subsets(const vector<int>& S, vector<int>& path, int step, vector<vector<int>>& result)
	{
		if (step == S.size())
		{
			result.push_back(path);
			return;
		}
		subsets(S, path, step + 1, result);
		path.push_back(S[step]);
		subsets(S, path, step + 1, result);
		path.pop_back();
	}
public:
	vector< vector<int> > subsets(vector<int>& S)
	{
		// Elements in a subset must be in non-descending order
		sort(S.begin(), S.end());
		vector< vector<int>> result;
		vector<int> path;
		
		subsets(S, path, 0, result);
		return result;
	}
};

void test_subsets()
{
	Subsets_Recursion solver;
	int a[] = {1, 2, 3};
	vector<int> S(a, a+ 3);
	std::vector<std::vector<int> > result = solver.subsets(S);
	for(auto a: result)
	{
		std::cout << "[";
		for(auto b: a)
		{
			std::cout << b << ",";
		}
		std::cout <<"]" <<  std::endl;
	}
}
int main(int argc, char const *argv[])
{
	test_subsets();
	return 0;
}