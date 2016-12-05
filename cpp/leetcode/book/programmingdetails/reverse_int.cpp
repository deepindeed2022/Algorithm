#include <iostream>

int reverse(int x)
{
    int r = 0;
    for(;x;x/=10)
    {
        r = r*10 + x%10;
    }
    return r;
}
int main(int argc, char const *argv[])
{
    int a = -3213;
    std::cout << reverse(a) << std::endl;
    return 0;
}