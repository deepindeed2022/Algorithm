/**
 * @description
 * The file is used to find the lowest common multipler of 3 numbers in [1..N]
 * 已知一个正整数N，问从1~N中任选出三个数，他们的最小公倍数最大可以为多少。
 * @author :wenlong.cao
 * @create: 2016-11-29
 **/

#include <iostream>
bool isodd(long long num)
{
    return num%2 == 1;
}
long long lcm(long long N)
{
    long long result = 1;
    if(isodd(N))
    {
        result = N*(N-1)*(N-2);
    }
    else
    {
        if(N % 3 != 0)
        {
            result = N*(N-1)*(N-3);
        }else
        {
            result = (N-1)*(N-2)*(N-3);
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
    long long N;
    std::cin >> N;
    //N = 95152;
    std::cout << lcm(N) << std::endl;
    return 0;
}