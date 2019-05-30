/**********************************************************************
/* test qsort and odd_even_sort performance
/* author: wenlong.cao
/*********************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <cassert>
#include <sys/time.h>
using namespace std;

static long get_current_time()
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000000 + tv.tv_usec;
}

//整數或浮點數皆可使用,若要使用物件(class)時必須設定大於(>)的運算子功能
template<typename T> 
void odd_even_sort(T arr[], int len) {
	int odd_even, i;
	bool sorted = false;
	while (!sorted) 
	{
		sorted = true;
		for (odd_even = 0; odd_even < 2; odd_even++)
			for (i = odd_even; i < len - 1; i += 2)
				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
					sorted = false;
				}
	}
}


long test_odd_even_sort(int length, int times)
{
	int *a = new int[length];
	srand(0);
	long total = 0;
	long start, end;
	for(int t = 0; t < times; ++t)
	{
		for(int i = 0; i<length; ++i) a[i] = rand()%10000;
		start = get_current_time();
		odd_even_sort(a, length);
		end = get_current_time();
		total += end - start;
	}
	delete a;
	return total;
}
long test_qsort(int length, int times)
{
	std::vector<int> a(length, 0);
	srand(0);
	long total = 0;
	long start, end;
	for(int t = 0; t < times; ++t)
	{
		for(int i = 0; i<length; ++i) a[i] = rand()%10000;
		start = get_current_time();
		std::sort(a.begin(), a.end());
		end = get_current_time();
		total += end - start;
	}
	return total;
}
int main(int argc, char const *argv[])
{
	static int MAX_NUM = 10000;
	std::vector<int> a(MAX_NUM, 0);
	srand(0);
	for(int i = 0; i<MAX_NUM; ++i) a[i] = rand()%10000;
	std::vector<int> b(a.begin(), a.end());
	int len = a.size();
	odd_even_sort(a.data(), len);
	std::sort(b.begin(), b.end());
	assert(equal(a.begin(), a.end(), b.begin()));
	long tq = test_qsort(MAX_NUM, 10);
	long t12 = test_odd_even_sort(MAX_NUM, 10);
	std::cout << "qsort use time:" << tq << std::endl;
	std::cout << "odd_even sort using time:" << t12 <<std::endl;
	std::cout << (double)(t12)/tq << std::endl;
	// for(int i = 0; i < len; ++i)
	// {
	// 	std::cout << a[i] << " ";
	// }
	// std::cout << std::endl;
	return 0;
}