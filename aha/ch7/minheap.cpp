#include <cstdio>
#include <algorithm>
using namespace std;

const static int MAX_LEN=101;
int minheap[MAX_LEN];
int data[MAX_LEN];
static int n = 0;

void shiftdown(int minheap[MAX_LEN], const int n, int i)
{
	bool flag = false;
	int t;
	while(i*2 <= n && !flag)
	{
		//t = minheap[i] > minheap[i*2] ? i*2 : i;
		if(minheap[i] > minheap[i*2])
			t = i << 1;
		else
			t = i;
		if(i*2+1 <= n)
			t = minheap[t] > minheap[i*2+1] ? i*2+1 : t;
		if(t != i)
		{
			swap(minheap[t], minheap[i]);
			i = t;
		}
		else
			flag = true;
	}
}
void shiftup(int i = n)
{
	bool flag = false;
	if(i == 1) return;
	while(i != 1 && !flag)
	{
		if(minheap[i] < minheap[i/2])
			swap(minheap[i], minheap[i/2]);
		else
			flag = true;
		i = i/2;
	}
}
int deletemin()
{
	int t = minheap[1];
	minheap[1] = minheap[n];
	n--;
	shiftdown(minheap, n, 1);
	return t;
}
int main(int argc, char const *argv[])
{
	int val;
	FILE* f;
	f = fopen("minheap.txt", "r");

	while(fscanf(f, "%d", &val) != EOF)
	{
		n++;
		minheap[n] = val;
		//data[n] = val;
	}
	for(int i = n/2; i>= 1; --i)
		shiftdown(minheap, n, i);

	for(int i = 1; i <= n;)
	{
		printf("%d ", deletemin());
	}
	printf("\n");

	return 0;
}