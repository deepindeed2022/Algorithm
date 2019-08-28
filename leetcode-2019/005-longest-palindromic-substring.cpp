#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int l = s.size();
        if(l < 2) return s;
		std::vector<std::vector<bool> > dp(l, std::vector<bool>(l, false));
		int col = 0;
		int row = 0;
		for(int i = 0; i < l; i++) dp[i][i] = true;
		for(int i = l-1; i >=0; i--) {
			for(int j = i+1; j < l; j++) {
				if(s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
					dp[i][j] = true;
					if (j - i + 1 > col - row + 1) {
                        row = i;
                        col = j;
                    }
				}
			}
		}
        return s.substr(row, col - row + 1);
    }
};

int main(int argc, char const *argv[])
{
	Solution solve;
	std::cout << solve.longestPalindrome("babad") << std::endl;
	std::cout << solve.longestPalindrome("bb") << std::endl;
	std::cout << solve.longestPalindrome("ac") << std::endl;
	std::cout << solve.longestPalindrome("aaaa") << std::endl;
	std::cout << solve.longestPalindrome("abcba") << std::endl;
	return 0;
}