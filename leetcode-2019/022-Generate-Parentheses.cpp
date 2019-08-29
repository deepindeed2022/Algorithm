#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<string> res;
        generate("", 0, 0, n, res);
        return res;
    }
private:
		void generate(std::string s, int left, int right, const int n, std::vector<string>& res) {
			if(left == n && right == n) {
				res.push_back(s);
			}
			if(left < n) {
				generate(s+"(", left+1, right, n, res);
			}
			if(right < left) {
				generate(s+")", left, right+1, n, res);
			}
		};
};

int main(int argc, char const *argv[])
{
	Solution solve;
	std::vector<std::string> res = solve.generateParenthesis(3);
	for(auto& s: res){
		std::cout << s << std::endl;
	}
	return 0;
}