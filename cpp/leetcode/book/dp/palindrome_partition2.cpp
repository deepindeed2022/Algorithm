/**********************************************************************************************
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = ”aab”,
Return 1 since the palindrome partitioning [”aa”,”b”] could be produced using 1 cut
@author: wenlong.cao
@date: 2016-12-04
/**********************************************************************************************/
#include <iostream>
#include <vector>
#include <string>

int minCut(std::string s)
{
    const int n = s.size();
    int f[n+1];
    bool p[n][n];
    std::fill_n(&p[0][0], n*n, false);
    for(int i = 0; i<= n;i++)
        f[i] = n - 1 -i;
    
    for(int i= n -1; i>=0;--i)
    {
        for(int j = i; j<n;++j)
        {
            if(s[i] == s[j] && (j-i < 2 || p[i+1][j-1]))
            {
                p[i][j] = true;
                f[i] = std::min(f[i], f[j+1] + 1);
            }
        }
    }
    return f[0];
}
int main(int argc, char const *argv[])
{
    std::string str("aabbbbbba");
    std::cout << minCut(str) << std::endl;
    return 0;
}