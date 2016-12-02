#include <cstring>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char* a = new char[100];
    char* b= new char[100];
   // a[99] = 0;
    //b[99] = 0;
    std::cout << memcmp(a, b, sizeof(b))<<std::endl;

    delete[] a;
    delete[] b;
    return 0;
}