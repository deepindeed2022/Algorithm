#include <iostream>

template<class T>
void printInt(T value)
{
    std::cout << value << std::endl;
}
int main(int argc, char const *argv[])
{
    int a =100;
    printInt<float>(a);
    printInt(a);
    std::cout << std::endl;

    float b = 100.3;
    printInt<float>(b);
    printInt<int>(b);
    printInt(b);
    std::cout << std::endl;

    short c = 123;
    printInt<float>(c);
    std::cout << std::endl;

    double d = 1234224523452345790567890456789423423434.453;
    printInt<double>(d);
    printInt<float>(d);
    std::cout << std::endl;
    return 0;
}