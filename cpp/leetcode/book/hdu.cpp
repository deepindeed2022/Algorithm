int perm(int a)
{
    if(a == 1) return 1;
    if(a == 2) return 2;
    if(a > 2) return a* (perm(a-1));
}
#include <iostream>

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 10; ++i)
    {
        std::cout << perm(i) << ",";
    }
    return 0;
}