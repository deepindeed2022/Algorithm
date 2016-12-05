#include <cassert>
#include <cstdio>
#include <cstdlib>
namespace TEST{

#define ASSERT(p)                       \
{                                       \
    assert(p);                  \
printf("THE LINE:%d ASSERT", __LINE__); \
}

#define PRINT_ARR(arr, n)       \
{                               \
    printf("THE LINE:%d OUTPUT:\n",__LINE__);   \
    for(int i= 0; i < n; ++i)   \
        printf("%d  ", arr[i]); \
    printf("\n");               \
} 
template<typename type>
void print_arr(type* arr, size_t n)
{
    PRINT_ARR(arr, n);
}
void generate_sorted_ary(std::vector<int>& a, const size_t size)
{
    // Generate test case data
    // srand(0);
    std::vector<int> a(size, 0);
    for (int i = 0; i < size; ++i)
    {
        a[i] = rand() % RANDOM_MAX;
    }
    std::sort(a.begin(),a.end());
    assert(std::is_sorted(a.begin(), a.end()));
}
}
