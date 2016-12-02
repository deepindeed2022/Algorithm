#include <iostream>

using namespace std;
#define M 10007
#include <math.h>
// int modfibonacci(int n, int a[])
// {
//     for (int i = 0; i < n-2; ++i)
//     {
//         a[i+2] = (a[i + 1]+ a[i]) % M;
//     }
//     return a[n-1]%M;
// }
int fib_binet(int n)
{
    return ((pow( (1+pow(5,0.5)),n ) - pow( (1-pow(5,0.5)),n ))/(pow(2.0,n)*pow(5,0.5)));
}
int fib_dp(int n)
{
    int a = 1;
    int b = 1;

    for(int i = 0; i < n -2; ++i)
    {
        b += a;
        a = b - a;
        if(a >= M)
        {
            a%= M;
            b%= M;
        }
    }
    return b;
}
int main(int argc, char const *argv[])
{
    int n;
    //std::cin >> n;
    n = 1000000;
    // int * a = new int [n];
    // a[0] = 1;
    // a[1] = 1;
    std::cout << fib_binet(n);
    //delete []a;
    return 0;
}