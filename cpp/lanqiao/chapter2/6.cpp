#include <iostream>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    char a[5];

    for (int i = 1001; i <=9999; ++i)
    {
        itoa(i, a, 10);

        if(a[0] == a[3] && a[1] == a[2])
            std::cout << i << std::endl;
    }
    return 0;
}