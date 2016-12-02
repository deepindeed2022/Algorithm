#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
using namespace std;
void test_iterator()
{
        const int arraysize = 7;
    int ia[arraysize] = {0,1,2,3,4,5,6};
    std::vector<int> ivec(ia, ia + arraysize);
    std::list<int> ilist(ia, ia + arraysize);
    std::deque<int> ideque(ia, ia + arraysize);

    std::vector<int>::iterator it1 = find(ivec.begin(), ivec.end(), 4);
    if(it1 == ivec.end())
        std::cout << "4 not found"<<std::endl;
    else
        std::cout << "4 have found " << *it1<<std::endl;

    std::list<int>::iterator it2 = find(ilist.begin(), ilist.end(), 6);
    if(it2 == ilist.end())
        std::cout << "6 not found"<<std::endl;
    else
        std::cout << "6 have found " << *it2<<std::endl;

    std::deque<int>::iterator it3 = find(ideque.begin(), ideque.end(), 8);
    if(it3 == ideque.end())
        std::cout << "8 not found"<<std::endl;
    else
        std::cout << "8 have found " << *it3<<std::endl;
}
#include <string>
#include <memory>

void test_smart_ptr()
{
    auto_ptr<string> ps(new string("Hello, auto_ptr"));
    std::cout << *ps << std::endl;
    std::cout << ps->size() << std::endl;    
}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 1000000; ++i)
    {
        test_smart_ptr();
    }
    
    return 0;
}
