#include <iostream>
#include <math.h>
#include <iomanip>
#include <assert.h>
using namespace std;

#define  PI atan(1.0)*4
double acreage(int r)
{
    return (double)(PI*r*r);
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin >>n;
    //n =10;
    assert(n <= 10000);
    assert(n >= 1);

    std::cout<< fixed << std::setprecision(7) << acreage(n);
    return 0;
}