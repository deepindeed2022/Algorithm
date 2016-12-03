#include <list>
#include <iostream>
#include <algorithm>
void test()
{
    using namespace std;
    int i;
    list<int> ilist;
    std::cout << "size=" << ilist.size() << std::endl;

    for(int j = 0; j < 5; ++j)
        ilist.push_back(j);
    std::cout << "size=" << ilist.size() << std::endl;

    list<int>::iterator ite;
    for(ite = ilist.begin(); ite != ilist.end(); ++ite)
    {
        std::cout << *ite << " ";
    }   
    std::cout << std::endl;
    ite = find(ilist.begin(), ilist.end(), 3);
    if(ite != ilist.end())
    {
        ilist.insert(ite, 99);
    }
    std::cout << "size="<<ilist.size() << std::endl;
    std::cout << *ite << std::endl;

    for(ite = ilist.begin(); ite != ilist.end(); ++ite)
    {
        std::cout << *ite << " ";
    }   
    std::cout << std::endl;

    ite = find(ilist.begin(), ilist.end(), 1);
    if(ite != ilist.end())
    {
        std::cout << *(ilist.erase(ite)) << std::endl;
    }

    for(ite = ilist.begin(); ite != ilist.end(); ++ite)
    {
        std::cout << *ite << " ";
    }   
    std::cout << std::endl;

}
void test_equal()
{
  std::list<int> a = {10, 20, 30};
  std::list<int> b = {10, 20, 30};
  std::list<int> c = {30, 20, 10};

  if (a == b) std::cout << "a and b are equal\n";
  if (b != c) std::cout << "b and c are not equal\n";
  if (b < c) std::cout << "b is less than c\n";
  if (c > b) std::cout << "c is greater than b\n";
  if (a <= b) std::cout << "a is less than or equal to b\n";
  if (a >= b) std::cout << "a is greater than or equal to b\n";
}
int main(int argc, char const *argv[])
{
    test_equal();
    return 0;
}