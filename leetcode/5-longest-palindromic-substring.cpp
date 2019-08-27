#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int l = s.size();
        if(l < 2) return s;
        int max_length = 1;
        std::string result = s.substr(0, 1);
        for(int i = 1; i < l - 1; i++) {
        	if(s[i-1] == s[i+1]) {
        		int c = 1;
        		for(int k = 1; k <= std::min(i - 1, l - i - 2); k++) {
        			if(s[i - 1 - k] == s[i +1 + k]) c++;
        			else break;
        		}
        		if(2*c + 1 > max_length) {
        			max_length = 2*c + 1;
        			result = s.substr(i - c, max_length);
        		}
        	}
        }
        for(int i = 0; i < l - 1; i++) {
        	if(s[i] == s[i+1]) {
        		int c = 1;
        		for(int k = 1; k <= std::min(i, l - (i+1)); k++) {
        			if(s[i - k] == s[i+1+k]) c++;
        			else break;
        		}
        		if(2*c > max_length) {
        			max_length = 2*c;
        			result = s.substr(i + 1 - c, max_length);
        		};
        	}
        }
        return result;
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