/**
 * 内存对齐和使用内存对齐的free 和allo的实现，reference OpenCV
 * 另外，其实在GNU系统中，由malloc或realloc返回的内存块的地址总是8的倍数(或者在64位系统上16倍)；
 * 如果你需要一内存块，其地址是2的更高次幂的倍数，那么可以用stdlib.h.文件中声明的aligned_alloc
 * 、posix_memalign
 **/
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

#define FAST_MALLOC_ALIGN 16
typedef unsigned char uchar;

template<typename _Tp> 
static inline _Tp* alignPtr(_Tp* ptr, int n=(int)sizeof(_Tp))
{
    return (_Tp*)(((size_t)ptr + n-1) & -n);
}

void fastFree(void* ptr)
{
    if(ptr) {
        uchar* udata = ((uchar**)ptr)[-1];
        assert(udata < (uchar*)ptr &&
               ((uchar*)ptr - udata) <= (ptrdiff_t)(sizeof(void*)+FAST_MALLOC_ALIGN));
        free(udata);
    }
}
void* fastAlloc(size_t size)
{
    // alloc the size include
    //      size
    //      pointer size
    //      aligen 

    uchar* udata = (uchar*)malloc(size + sizeof(void*) + FAST_MALLOC_ALIGN);
    if(!udata) {
        std::cerr << "Alloc memory Failed"<< std::endl;
        return NULL;
    }
    uchar** adata = alignPtr((uchar**)udata + 1, FAST_MALLOC_ALIGN);
    adata[-1] = udata;
    return adata;
}

int main(int argc, char const *argv[])
{
    int** a;
    a = new int*[2];
    for(int i = 0; i < 2; ++i) {
        a[i] = new int[11];
        std::cout<< a[i] <<std::endl;
        a[i] = alignPtr(a[i], 16);
        std::cout<<"align:"<< a[i] <<std::endl;
    }
    for(int i = 0; i < 2; ++i) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}