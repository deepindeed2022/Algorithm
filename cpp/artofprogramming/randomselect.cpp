/**
* @author: Clython 
* @description: RandomSelect Kth min from a array.
* @create Date:2016-11-1
**/
#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::swap;
#define FUNC_PARAM int* A, int start, int end, int i
typedef int(*PF_RET_VOID)(FUNC_PARAM);

int partition(int* A, int start, int end)
{
	int x = A[end];
	int i = start - 1;
	for(int j = start; j < end; ++j)
	{
		if(A[j] <= x)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[end]);
	return i + 1;
}
int random_partition(int* A, int start, int end)
{
	int i = rand()%(end - start) + start;
	swap(A[end], A[i]);
	return partition(A, start, end);
}
int randomselect (FUNC_PARAM)
{
	//The is your code
	if(start == end)
		return 	A[start];
	int q = random_partition(A, start, end);
	int k = q - start + 1;
	if(i <= 0)　i = 1;　// handle the special case i out of low bound
	if(k == i)
		return A[q];
	else if(i < k)
	{
		return randomselect(A, start, q - 1, i);
	}
	else
	{
		return randomselect(A, q + 1, end, i - k);
	}
}
void test_all(PF_RET_VOID p)	
{
	int a[] = {13, 12, 11, 10, 9, 8, 7, 6,5,4,3,2,1};
	int size = 13;
	assert(12 == (*p)(a, 0, size -1, 12));
	assert(13 == (*p)(a, 0, size -1, 14));
	assert(1 == (*p)(a, 0, size -1, -1));
	assert(13 == (*p)(a, 0, size -1, 13));

}
int main(int argc, char const *argv[])
{
	test_all(randomselect);
	return 0;
}
