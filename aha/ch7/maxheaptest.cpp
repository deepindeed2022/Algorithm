#include "maxheap.h"
extern int aha::n;
void heapsort(int* maxheap, const int n)
{
	int num = n;
	while(num > 1)
	{
		std::swap(maxheap[1], maxheap[num]);
		num--;
		aha::shiftdown(maxheap, num, 1);
	}
}
int main(int argc, char const *argv[])
{
	int val;
	FILE* f;
	f = fopen("maxheap.txt", "r");

	while(fscanf(f, "%d", &val) != EOF)
	{
		aha::n++;
		aha::maxheap[aha::n] = val;
	}
	// 建堆
	aha::create_maxheap();
	// 堆排序
	heapsort(aha::maxheap, aha::n);
	//从小到大输出堆
	for(int i = 1; i <= aha::n; ++i)
	{
		printf("%d ", aha::maxheap[i]);
	}
	printf("\n");

	return 0;
}