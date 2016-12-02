#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int* pi = new int(5);
    const int* pci = new int(9);

    *pi = 7;
    std::cout << "passing" << std::endl;
    
    
    return 0;
}