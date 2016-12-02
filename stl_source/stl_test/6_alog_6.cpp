#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;
template <class T>
struct display{
    void operator()(const T& x)const
    {
        std::cout << x << " ";
    }
};
int main(int argc, char const *argv[])
{
    string stra1[] = {"Jamie", " JJHou","Jason"};  
    string stra2[] = {"Jamie", " JJhou","Jerry"};
    std::cout << boolalpha << lexicographical_compare(stra1, stra1 +2 , stra2, stra2 + 2) << std::endl;
    std::cout << boolalpha << lexicographical_compare(stra1, stra1 +2 , stra2, stra2 + 2, greater<string>()) <<std::endl;
    std::vector<string> strvec(stra1, stra1 + 2);
    std::vector<string>::iterator ite1 = strvec.begin();
    std::vector<string>::iterator ite2 = ite1;
    std::advance(ite2, 1);
    std::cout << *ite1 << " "<<*ite2 << std::endl;
    std::iter_swap(ite1, ite2);
    std::cout << *ite1 << " "<<*ite2 << std::endl;

    return 0;
}