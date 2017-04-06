#include "minheap.h"
using namespace aha;
extern int aha::minheap[MAX_LEN];
extern int aha::n;
int main(int argc, char const *argv[])
{
	int val;
	FILE* f;
	f = fopen("minheap.txt", "r");

	while(fscanf(f, "%d", &val) != EOF)
	{
		aha::n++;
		aha::minheap[n] = val;
		//data[n] = val;
	}
	for(int i = n/2; i>= 1; --i)
		aha::shiftdown(minheap, n, i);

	//从小到大输出堆
	for(int i = 1; i <= n;)
	{
		printf("%d ", aha::deletemin());
	}
	printf("\n");

	return 0;
}