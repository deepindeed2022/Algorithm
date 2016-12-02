/********************************************************************************
 从键盘读入n个整数放入数组中，编写函数CompactIntegers，删除数组中所有值为0的元素，
 其后元素向数组首端移动。注意，CompactIntegers函数需要接受数组及其元素个数作为参
 数，函数返回值应为删除操作执行后数组的新元素个数。输出删除后数组中元素的个数并
 依次输出数组元素。
 *********************************************************************************/
#include <iostream>
int CompactIntegers(int a[], size_t n)
{
    int* nzeros = new int[n];
    int nstep = 0;
    for(int i = 0; i < n; ++i)
    {
        nzeros[i] = nstep;
        if(a[i] == 0)
        {
            ++nstep;
            nzeros[i] = 0;
        }
    }
    for(int i = 0; i < n; ++i)
        a[i - nzeros[i]] = a[i];
    
    delete[] nzeros;
    return n - nstep;

}
int main(int argc, char const *argv[])
{
    // int n =5;
    // int a[] = {3,4,0,0,2};
    int n;
    std::cin >> n;
    int *a = new int[n];
    for(int i= 0 ; i< n; ++i)
    {
        std::cin >> a[i];
    }
    //std::cout << CompactIntegers(a, n) << std::endl;
    int newn = CompactIntegers(a, n);
    std::cout << newn <<std::endl;
    for(int i = 0; i < newn; ++i)
    {
        std::cout<< a[i] << " ";
    }
    return 0;
}