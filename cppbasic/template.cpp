/****************************************************************
 * 源代码中包含
 * 1. 指针函数类型的使用
 * 2. 使用指针函数时，测试程序的调用实现，为后面多种方案的测试提供了参考
 *
**/

#include <iostream>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <vector>

#include <queue>
using std::priority_queue;

#define RANDMAX 0x7FFFFFFFF

#define FUNC_PARAM std::vector<int>& test_arr, const int size, int k

typedef std::vector<int>(*PF_RET_VOID)(FUNC_PARAM);

void test_all(PF_RET_VOID p, int n, int k);

#include <sys/time.h>
static long get_current_time()
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000000 + tv.tv_usec;
}

// Time is O(n) + O(nlogn) = O(nlogn))
std::vector<int> min_k_num_sort (FUNC_PARAM)
{
    std::cout << __FUNCTION__;
    sort(test_arr.begin(), test_arr.end());
    std::vector<int> result(test_arr.begin(), test_arr.begin()+k);
    return result;
}
//(n-k)k = O(nk)
std::vector<int> min_k_num_select(FUNC_PARAM)
{
    std::cout << __FUNCTION__;
    // init knum to save the result
    std::vector<int> knum(k, 0);
    int kmax = 0;
    int index = -1;
    // init kmin with the input vector's pre kth elements
    // mean while get the max element in [0..k-1] and its index
    for (int i = 0; i < k; ++i)
    {
        knum[i] = test_arr[i];
        if (test_arr[i] > kmax) 
        {
            kmax = test_arr[i];
            index = i;
        }
    }

    
    for(int i = k; i< test_arr.size(); ++i)
    {
        if(test_arr[i] > kmax)
        {
            knum[index] = test_arr[i];
            kmax = test_arr[i];
            // select max number again
            for (int ki = 0; ki < k; ++ki)
            {
                if (knum[ki] > kmax)
                {
                    kmax = knum[ki];
                    index = ki;
                }
            }
        }
    }
    return knum;
}
// Time is O(nlogn)
std::vector<int> min_k_num_maxheap (FUNC_PARAM)
{
    std::cout << __FUNCTION__;
    std::priority_queue<int> kheap;
    for (int i = 0; i < k; ++i)
    {
        kheap.push(test_arr[i]);
    }
    for (int i = k; i < test_arr.size(); ++i)
    {
        if(kheap.top() > test_arr[i])
        {
            kheap.pop();
            kheap.push(test_arr[i]);
        }
    }
    std::vector<int> result(k, 0);
    for (int i = k-1; i >=0; --i)
    {
        result[i]= kheap.top();
        kheap.pop();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    const int size = 10000000;
    test_all(min_k_num_sort,    size, 10);
    test_all(min_k_num_select,  size, 10);
    test_all(min_k_num_maxheap, size, 10);
    return 0;
}
void test_all(PF_RET_VOID p, int n, int k)  
{
    clock_t start, finish;
    srand(0);
    std::vector<int> test_arr(n, 0);
    for(int i = 0; i < n; ++i) test_arr[i] = rand()%RANDMAX;
#ifdef OUTPUT
    for (std::vector<int>::iterator i = test_arr.begin(); i != test_arr.end(); ++i)
    {
        std::cout << (*i) << " ";
    }
#endif
    std::cout << std::endl;
    start = clock();
    std::vector<int> v =(*p)(test_arr, n, k);
    finish = clock();
    double totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    std::cout << " TEST USING:" << totaltime << "s"<<std::endl;
#ifdef OUTPUT   
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        std::cout << (*i) << " ";
    }
#endif
}