//
// Heap's algorithm
// Heap's algorithm generates all possible permutations of n objects. 
// It was first proposed by B. R. Heap in 1963.[1] 

// The algorithm minimizes movement: 
// it generates each permutation from the previous one by interchanging 
// a single pair of elements; the other n−2 elements are not disturbed. 
// In a 1977 review of permutation-generating algorithms, Robert Sedgewick 
// concluded that it was at that time the most effective algorithm for 
// generating permutations by computer.[2]
// reference:
// https://en.wikipedia.org/wiki/Heap%27s_algorithm
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void perm_fast(std::vector<int>& l, const int n)
{
	if(n == 1)
	{
		for(auto i: l)std::cout << i <<" ";
		std::cout << std::endl;
	}
	else
	{
		for(int i = 0; i < n - 1; ++i)
		{
			perm_fast(l, n - 1);
			if(n % 2 == 0)
				std::swap(l[i], l[n-1]);
			else
				std::swap(l[n-1], l[0]);
		}
		perm_fast(l, n - 1);
	}

}
void perm_backtrack(std::vector<int>& l, const int n)
{
	if(n == 1)
	{
		for(auto i: l)std::cout << i <<" ";
			std::cout << std::endl;
	}

	for(int i = 0; i < n; ++i)
	{
		std::swap(l[i], l[n-1]);
		perm_backtrack(l, n -1);
		std::swap(l[i], l[n-1]);
	}
}

void dfs(std::vector<int>& a, std::vector<bool>& book, int step, const int n)
{
	int i;
	if(step == n)
	{
		for(auto i: a)std::cout << i << " ";
		std::cout << std::endl;
	}
	else
	{
		for(int i = 0; i < n ; ++i)
		{
			if(!book[i])
			{
				a[step] = i+1;
				book[i] = true;
				dfs(a, book, step + 1, n);
				book[i] = false;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	// for(int i = 0; i < 3; ++i) a[i] = i+1;
	// perm_backtrack(a, 3);
	// for(int i = 0; i < 3; ++i) a[i] = i+1;
	// perm_fast(a, 3);
	const int n = 3;
	std::vector<int> a(3, 0);
	std::vector<bool> book(3, false);
	dfs(a, book, 0, 3);
	return 0;
}