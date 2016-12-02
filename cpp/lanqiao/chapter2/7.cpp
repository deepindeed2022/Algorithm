#include <iostream>

#define POWER_3(x) (x*x*x)

int main(int argc, char const *argv[])
{
    int unit;
    int dec;
    int hund;
    for(int i = 100; i < 1000; ++i)
    {
        unit = i % 100;
        hund = i / 100;
        dec = unit / 10;
        unit %= 10;
        if(i == POWER_3(unit)+POWER_3(dec)+POWER_3(hund))
            std::cout << i << std::endl;
    }
    return 0;
}