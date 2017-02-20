#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;
const vector<string> keyboard{"", "","abc","def","ghi","jkl","mno", "pqrs","tuv","wxyz"};
void dfs(const string& digits, size_t cur, string path, vector<string>& result)
{
    if(cur == digits.size())
    {
        result.push_back(path);
        return;
    }
    for(auto c: keyboard[digits[cur] - '0'])
    {
        dfs(digits, cur+1, path+c, result);
    }
}
std::vector<string> letterCombinations(const string& digits)
{
    vector<string> result;
    dfs(digits, 0,"", result);
    return result;
}

void test_letterCombination()
{
    string input = "23";
    std::vector<string> v = letterCombinations(input);
    std::vector<string> expectedresult = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    for(auto s: expectedresult)
    {
        assert(v.end() != find(v.begin(), v.end(), s));
    }
}
int main(int argc, char const *argv[])
{
    test_letterCombination();
    return 0;
}