#include <iostream>
#include <algorithm>
using std::distance;
using std::unique;
#include "utility.h"

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
//	PRINT_ARR(a, 9);
	int b[] = {1, 2, 2, 2, 2, 3, 3, 4, 4};
	assert(4 == removeDuplicates_2(b, 9));
//	PRINT_ARR(b, 9);

	return 0;
}