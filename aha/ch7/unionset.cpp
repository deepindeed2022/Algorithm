#include <cstdio>
#include <cstdlib>
#include <algorithm>

const static int MAX_LEN = 101;
int find[MAX_LEN];

inline void init(int* f, const int n) 
{
	for(int i = 1; i <= n; ++i) f[i] = i;
}
int getfather(int v)
{
	// int father = v;
	// while(find[father] != father)
	// {
	// 	father = find[father];
	// }
	// return father;
	// 采用递归方式实现
	// 每次在函数返回的时候，将
	if(find[v] == v)
	{
		return v;
	}
	else
	{
		find[v] = getfather(find[v]);
		return find[v];
	}
}
void merge(int v, int u)
{
	if(v > u) return merge(u, v);
	int t1, t2;
	t1 = getfather(v);
	t2 = getfather(u);
	if(t1 != t2)
	{
		find[t2] = t1;
		// 靠左原则，左边的变成右边的boss
	}
}
int main(int argc, char const *argv[])
{
	FILE* f;
	f = fopen("unionset.txt", "r");
	int n, m, sum = 0;
	int first, second;
	fscanf(f, "%d %d", &n, &m);
	init(find, n);
	for(int i = 0; i < m; ++i)
	{
		fscanf(f, "%d %d", &first, &second);
		merge(first, second);
	}
	for(int i = 1; i <= n; ++i)
	{
		printf("%d ",find[i]);
		if(find[i] == i)
		{
			//printf("%d ", i);
			sum++;
		}
	}
	printf("\n");
	printf("犯罪团伙个数：%d \n", sum);
	return 0;
}