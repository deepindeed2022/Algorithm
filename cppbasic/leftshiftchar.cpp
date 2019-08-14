/**
 * @author: wenlong.cao
 * @file: Define a left shift string function. The time compleity should O(n) and 
 *		  Space complexity should be O(1)
 * @date: 2016-10-31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef void(*tpf)(char[],const int, int);
void left_shift_onebit(char* s, const int n)
{
	char t = s[0];
	for(int i = 1; i < n; ++i)
	{
		s[i - 1] = s[i];
	}
	s[n-1] = t;
}
void left_shift_method_1(char* s, const int n, int m)
{
	while(m--)
	{
		left_shift_onebit(s, n);
	}
}
void test_left_shift(tpf func)
{
	char a[] = "abcdfg";
	int size = strlen(a);
	tpf f = func;
	f(a, size, 2);
	assert(strcmp(a, "cdfgab") == 0);

}
int main(int argc, char const *argv[])
{
	test_left_shift(left_shift_method_1);
	return 0;
}