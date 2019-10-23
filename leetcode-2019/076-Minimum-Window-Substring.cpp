#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

class Solution {
public:
	bool include_all(int count[256], int target_count[256], string& t) {
		for(auto& c: t) {
			if(count[c-'\0'] < target_count[c-'\0']) {
				return false;
			}
		}
		return true;
	}
    string minWindow(string s, string t) {
    	if(t.size() == 0 || s.size() < t.size()) return "";
        int count[256];
        int target_count[256];
        memset(count, 0, 256*sizeof(int));
        memset(target_count, 0, 256*sizeof(int));
        for(auto&c: t) target_count[c - '\0']++;
        int res_i = s.size();
   		int min_window = s.size() + 1;
        int i = 0;
        int j = 0;
        while(j < s.size()) {    	
	        do {
	        	count[s[j]-'\0']++;
	        	j++;
	        } while(j < s.size() && !include_all(count, target_count, t));
	       	if(j < s.size() && min_window > j - i) {
        		res_i = i;
        		min_window = j - i;
        	}
        	bool h = false;
	        while(i < j && include_all(count, target_count, t)){
	        	count[s[i]-'\0']--;
	       		i++;
	       		h = true;
	        } 
        	if(h &&  min_window > j - i + 1) {
        		res_i = i - 1;
        		min_window = j - i + 1;
        	}
        }
        return s.substr(res_i, min_window);
    }
};

int main(int argc, char const *argv[])
{
	Solution solve;
	std::string S = "ab";
	std::string T = "a";
	std::cout << solve.minWindow(S, T) << std::endl;
	std::string S1 = "ADOBECODEBANC";
	std::string T1 = "ABC";
	std::cout << solve.minWindow(S1, T1) << std::endl;
	std::string S2 = "a";
	std::string T2 = "a";
	std::cout << solve.minWindow(S2, T2) << std::endl;
	return 0;
}