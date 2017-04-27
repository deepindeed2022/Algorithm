/**********************************************************************************************
    Given two words word1 and word2, find the minimum number of steps required to convert word1 to
    word2. (each operation is counted as 1 step.)
    You have the following 3 operations permitted on a word:
    • Insert a character
    • Delete a character
    • Replace a character
/**********************************************************************************************/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
class Solution {
    public: int minDistance(const string & word1, const string & word2) {
        const size_t n = word1.size();
        const size_t m = word2.size();
        // 长度为 n 的字符串，有 n+1 个隔板
        int f[n + 1][m + 1];
        for (size_t i = 0; i <= n; i++) f[i][0] = i;
        for (size_t j = 0; j <= m; j++) f[0][j] = j;

        for (size_t i = 1; i <= n; i++) // word1 iter
        {
            for (size_t j = 1; j <= m; j++) // word2 iter
            {
                if (word1[i - 1] == word2[j - 1]) 
                	f[i][j] = f[i - 1][j - 1];
                else 
                {
                    int mn = min(f[i - 1][j], f[i][j - 1]);
                    f[i][j] = 1 + min(f[i - 1][j - 1], mn);
                }
            }
        }
        return f[n][m];
    }
};
int main(int argc, char const *argv[])
{
	Solution solve;
	string a = "hello";
	string b = "2hello2";
	assert(solve.minDistance(a, b) == 2);
	assert(solve.minDistance("helllo","hel2o") == 2);
	assert(solve.minDistance("hello","") == 5);
	assert(solve.minDistance("hehe","hhehhe") == 2);
	std::cout << "TEST PASSED"<<std::endl;
	return 0;
}