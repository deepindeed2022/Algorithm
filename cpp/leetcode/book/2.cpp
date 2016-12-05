#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int N;
    int n;
    long  ret = 0;
    cin >>N;
    for(int i = 0; i < N; i++)
    {
        cin >> n;
        if( N < 1000000)
        {
            long double sum = 0;
            for (long long j = 1; j <= n; ++j)
            {
                sum += (1.0/j);
            }
            ret = floor(sum);
        }else
            ret = floor(log(N+1) + 0.57721566490);
    }
    std::cout << ret << 
    return 0;
}