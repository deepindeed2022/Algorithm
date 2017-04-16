#include <cstdio>
#include <cstdlib>
#include <algorithm>
using std::min;
float f[101];
int main(int argc, char const *argv[])
{
	int P, Q, N;
	FILE* file;
	file = fopen("terms.txt", "r");
	fscanf(file, "%d %d %d", &P, &Q, &N);
	// 获取不同P不同概率的时候，获得一件物品的期望任务次数
	f[100] = 1.0f;
	for(int i = 99; i >= 0; i--)
	{
		//计算如果这次任务没获得，下一个任务获得的概率
		int j = min(i + Q, 100);  
		//i%的概率1次获得，(1-i%)的概率是从j%起始的期望任务数+1
		f[i] = ((float)i/100.0f) + (1.0 - ((float)i/100.0f))*(f[j] + 1);
	}
	// for(int i = 0; i < 101; ++i)
	// 	printf("%f ", f[i]);
	int sp;
	float sum = 0.0f;
	if(N < 8)
	{	
		for(int i = 1; i <= N; i++)
		{
			sp = floor(P/pow(2,i-1));
			sum += f[sp];
		}
	}
	else
	{
		for(int i = 1; i <= 7; i++)
		{
			sp = floor(P/pow(2,i-1));
			sum += f[sp];
		}
		sum += f[0]*(N - 7);
	}
	printf("sum: %f\n", sum);
	return 0;
}