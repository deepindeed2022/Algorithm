#include <iostream>
#include <cassert>
#include <cstdio>
#include <algorithm>
using std::distance;
using std::unique;
#define ASSERT(p) 						\
{										\
	assert(p);					\
printf("THE LINE:%d ASSERT", __LINE__);	\
}

#define PRINT_ARR(arr, n)		\
{								\
	printf("THE LINE:%d OUTPUT:\n",__LINE__);	\
	for(int i= 0; i < n; ++i)	\
		printf("%d  ", arr[i]);	\
	printf("\n");				\
}

int removeDuplicates_1(int A[], int n) 
{
	if (n == 0) return 0;
	int index = 0;
	for (int i = 1; i < n; i++) {
		if (A[index] != A[i])
			A[++index] = A[i];
	}
	return index + 1;
}
int removeDuplicates_2(int A[], int n) 
{
	return distance(A, unique(A, A+n));
}

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 2, 2, 2, 3, 3, 4, 4};
	assert(4 == removeDuplicates_1(a, 9));
	PRINT_ARR(a, 9);
	int b[] = {1, 2, 2, 2, 2, 3, 3, 4, 4};
	assert(4 == removeDuplicates_2(b, 9));
	PRINT_ARR(b, 9);
	PRINT_ARR(unique(b, b +9), 9)
	return 0;
}