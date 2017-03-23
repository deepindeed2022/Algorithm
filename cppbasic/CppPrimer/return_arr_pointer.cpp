#include <stdio.h>
#include <stdlib.h>

void* func_new(const int size)
{
	int* a = new int[size];
	for (int i = 0; i < size; ++i)
	{
		a[i] = 0;
	}
	//printf("%d\n", &a);
	return (void*)a;
}
void* func_arr()
{
	int a[100];
	for (int i = 0; i < 100; ++i)
	{
		a[i] = 0;
	}
	return (void*)a;
}
int main(int argc, char const *argv[])
{
	int* a = (int*)func_arr();
	printf("%d\n", &a);
	for (int i = 0; i < 100; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}