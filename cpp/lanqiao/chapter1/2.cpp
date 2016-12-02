#include <iostream>
typedef long long mRetType;
mRetType sum(long long  n)
{
    return (n+1)*n/2;
}
int main(int argc, char const *argv[])
{
    long long n;
    std::cin >> n;
    std::cout << sum(n);
    return 0;
}