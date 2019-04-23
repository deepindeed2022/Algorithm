#include <cstdio>
#include <cstdlib>
#include <cstring>

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
	int** a = (int**)new int[1];
	*a = new int[100];
	memset(*a, 0, 100*sizeof(int));

	return (void**)a;
}
int main(int argc, char const *argv[])
{
	int** a = (int**)func_arr();

	for (int i = 0; i < 100; ++i)
	{
		printf("%d ", (*a)[i]);
	}
	printf("\n");
	delete []*a;
	delete []a;
	return 0;
}