#include <stddef.h>
#include <iostream>
#include <assert.h>
#include <vector>
#include <iterator>
#include <typeinfo>

int main(int argc, char const *argv[])
{
    int a[] = {1, 2,3,4,5,6,7,8,45,3,34,2,24,24,2,42,34,23,4,234,23,42,342,4,23,3};
    const int size = sizeof(a)/sizeof(int);
    ptrdiff_t diff = &(a[size - 1]) - a;
    assert(sizeof(ptrdiff_t) == 4);
    std::cout <<"ptrdiff_t size: " << sizeof(diff) << std::endl;
    std::cout << diff << std::endl;


    std::vector<int> v(a, a + size);
    std::vector<int>::iterator it =  std::prev(v.end());
    std::vector<int>::difference_type diffvec = it - v.begin();
    std::cout << diffvec << std::endl;
    const std::type_info& info = typeid(ptrdiff_t);
    std::cout <<"ptrdiff_t: "<< info.name() << std::endl;

    const std::type_info& info1 = typeid(diffvec);
    std::cout <<"difference_type: "<< info1.name() << std::endl;
    return 0;
}