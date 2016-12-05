/**********************************************************************************************
    Given s1; s2; s3, find whether s3 is formed by the interleaving of s1 and s2.
    For example, Given: s1 = ”aabcc”, s2 = ”dbbca”,
    When s3 = ”aadbbcbcac”, return true.
    When s3 = ”aadbbbaccc”, return false.
/**********************************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
#include <vector>
using std::string;
using std::vector;
// The following iterative method is ERROR,such as case 1
// 
bool is_interleave_str(std::string s1, std::string s2, std::string s3)
{
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int k = s3.size() - 1;
    if(k != i+j+1) return false;
    bool result = true;
    while(i >= 0 && j >= 0 && k >= 0 && result)
    {

        if(s3[k] == s1[i])
        {
            i--; k--;
        }
        else if(s2[j] == s3[k])
        {
            j--;
            k--;
        }else
        {
            result = false;
        }
    }
    if(result)
    {
        if(i >= 0)
        {
            std::cout << "stabi:"<< i << std::endl;
            std::cout << "stabk:" << k << std::endl;
            while(i >= 0 && s3[k] == s1[i]){k--;i--;}
            if(i >= 0) result = false;
        }
        else if(j >= 0)
        {
            std::cout << "stab j:" << j <<std::endl;
            std::cout << "stab k:" << k << std::endl;
            while(j >= 0 && s2[j] == s3[k])
            {
                k--;
                j--;
            }
            std::cout << "stab j:" << j <<" "<< s2 << std::endl;
            std::cout << "stab k:" << k <<" "<< s3 << std::endl;
            if(j >= 0) result = false;
        }
    }
    return result;

}
// DP method
int isInterleave(string s1, string s2, string s3)
{
    if(s3.length() != s1.length() + s2.length())return false;
    vector<vector<bool> > f(s1.length() + 1, vector<bool>(s2.length() + 1, true));
    for(size_t i = 1; i <= s1.length();++i)
        f[i][0] = f[i-1][0] && s1[i-1] == s3[i-1];
    
    for(size_t i = 1; i <= s2.length();++i)
        f[0][i] = f[0][i-1] && s2[i-1] == s3[i-1];

    for(size_t i = 1; i <= s1.length(); ++i)
    {
        for(size_t j = 1; j<= s2.length();++j)
        {
            f[i][j] = (s1[i-1] == s3[i+j-1] && f[i-1][j]) || (s2[j-1] == s3[i+j-1] && f[i][j-1]);
        }
    }
    return f[s1.length()][s2.length()];
}
void test_case_1()
{
    std::string s1 = "aabc";
    std::string s2 = "abad";
    std::string s3 = "aabadabc"; 
    assert(isInterleave(s1,s2,s3));
    //assert(is_interleave_str(s1,s2,s3));
}
int main(int argc, char const *argv[])
{
    test_case_1();
    return 0;
}