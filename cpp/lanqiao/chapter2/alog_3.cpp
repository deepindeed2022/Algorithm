/*****************************************************************************
 * 问题描述
如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，那么我们就说这个
数是K好数。求L位K进制数中K好数的数目。例如K = 4，L = 2的时候，所有K好数为
11、13、20、22、30、31、33 共7个。由于这个数目很大，请你输出它对1000000007
取模后的值。

* 输入格式
输入包含两个正整数，K和L。

*输出格式
输出一个整数，表示答案对1000000007取模后的值。
*****************************************************************************/
#include <iostream>
#include <string.h>  
#include <algorithm>  
using namespace std;

#define MOD 1000000007
__int64 dp[101][101];

int main(int argc, char const *argv[])
{
    int K = 4, L = 2;
    // std::cin >> K >> L;
    for(int i = 0; i < K; ++i)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= L; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            for (int c = 0; c < K; ++c)
            {
                if(c != j-1 && c != j + 1)
                {
                    dp[i][j] += dp[i-1][c];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    __int64 sum = 0;
    for (int i = 1; i < K; ++i)
    {
        sum += dp[L][i];
        sum %= MOD;
    }
    std::cout << sum << std::endl;
    for (int i = 1; i <= L; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
           std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}