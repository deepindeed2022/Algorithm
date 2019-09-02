#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string common = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string common_current = ""; 
            int j = 0;
            while(j < strs[i].size() && common[j] == strs[i][j]){       
                common_current += common[j];
                j++;
            }
            common = common_current;
        }
        return common;
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}