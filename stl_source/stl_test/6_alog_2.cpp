#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// The following struct called functor
template <class T>
struct plus2
{
    void operator()(T& x)const
    {
        x +=2;
    }
};

template <class T>
class print
{
public:
    void operator()(T& x)const
    {
        std::cout << x << " ";
    }
};
void fprint(int a)
{
    std::cout << a << " ";
}

int main(int argc, char const *argv[])
{
    int ia[] = {22,30,30,17,33,40,17,23,22,12,20};
    std::vector<int> iv(ia, ia + sizeof(ia)/sizeof(int));
    for_each(iv.begin(), iv.end(), print<int>());
    std::cout << std::endl;
    for_each(iv.begin(), iv.end(), plus2<int>());
    for_each(iv.begin(), iv.end(), print<int>());
    std::cout  << std::endl;
    for_each(iv.begin(), iv.end(), fprint);
    return 0;
}