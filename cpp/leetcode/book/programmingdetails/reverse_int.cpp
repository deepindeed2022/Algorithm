#include <iostream>

long long reverse(int x)
{
    long long r = 0L;
    for(; x; x/=10)
    {
        r = r*10 + x%10;
    }
    return r;
}
int main(int argc, char const *argv[])
{
    int a =  1000000003;
    std::cout << reverse(a) << std::endl;
    return 0;
}