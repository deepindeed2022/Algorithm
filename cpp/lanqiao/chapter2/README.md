# DP训练营
## TEST 1- K好数
*问题描述*
如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，那么我们就说这个数是K好数。求L位K进制数中K好数的数目。例如K = 4，L = 2的时候，所有K好数为11、13、20、22、30、31、33 共7个。由于这个数目很大，请你输出它对1000000007取模后的值。
*输入格式*
输入包含两个正整数，K和L。
*输出格式*
输出一个整数，表示答案对1000000007取模后的值。
*样例输入*
4 2
*样例输出*
7
*数据规模与约定*
对于30%的数据，KL <= $10^6$；
对于50%的数据，K <= 16， L <= 10；
对于100%的数据，1 <= K,L <= 100。
*问题分析*
1. dp[i][j],其中i代表的是数字有几位，j代表首位放j的情况有几种。放置的过程是从最后一位开始放，每次放置完i位时，首位是j的方法数为dp[i][j];
2. 注意的问题是，0唯一作为首位的情况是0
3. 数据规模要定位正确

>解答：DP法，dp[i][j], i表示位数为i时，末尾位为j时总共的种数。
状态转移方程为：dp[i][j]= sum(dp[i-1][p]) (p != j+1 && p!=j-1)
注意，此题假设当只有一位的时候，这一位也不能为0。
代码：

```cpp
#include <iostream>
#include <stdio.h>
#include <string.h>
#define LONG long long 
#define mod 1000000007
using namespace std;

int main()
{
    LONG dp[110][110];
    int i, j, p;
    int k, l;
    LONG sum;
    cin>>k>>l;
    //k=4; l=2;
    {
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= k; i++)
        {
            dp[1][i] = 1;
        }
        dp[1][0] = 0;
        for (i = 2; i <= l; i++)
            for (j = 0; j < k; j++)
                for (p = 0; p < k; p++)
                {
                    if (p == j - 1 || p == j + 1)//当前的条件
                        continue;
                    dp[i][j] += dp[i - 1][p];
                    dp[i][j] = dp[i][j] % mod;
                }
        sum = 0;//计算最后所有的可能
                for (i = 0; i < k; i++)
        {
            sum += dp[l][i];
            sum %= mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
```
**以上分析不对。**

>正确的分析：
实际上，当只有一位的时候，它是可以为0的。当总位数大于1位时，第一位的取值范围为：1-(k-1)，其他位的取值范围为：0-(k-1)。所以，第一位是特殊位。大问题变成小问题时，大问题应该是小问题每一次在首位添加一个值组成的，这样每次首位都是添加(1-(k-1))的某一位。若大问题变成小问题时，大问题应该是小问题每一次在尾位添加一个值组成的，当总位数为1位时，和总位数为其他时，尾位添加的数的取值范围不一样。故，以上的dp表达式不对。

>应为：
dp[i][j], i表示位数为i时，首位为j时总共的种数。
状态转移方程为：
$$dp[i][j]= \sum_{p=0}^{p=k-1}{dp[i-1][p]} (p != j+1 && p!=j-1)， 1 <= j <= k-1$$

>正确的代码：

```cpp
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
```