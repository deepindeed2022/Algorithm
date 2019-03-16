#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

// void matrix_multiply(int** a, int **b, int **c, int ra, int ca, int rb, int cb)
// {
// 	if(ca!= rb) std::cerr << "矩阵不可乘" << std::endl;
// 	for(int i = 0; i < ra; i++)
// 	{
// 		for(int j = 0; j < cb; ++j)
// 		{
// 			int sum = a[i][0]*b[0][j];
// 			for(int k = 1; k < ca; k++)
// 				sum += a[i][k]*b[k][j];
// 			c[i][j] = sum;
// 		}
// 	}
// }
void matrix_chain(int* p,const int n, int **m, int **s)
{
	for(int i = 1; i <= n; ++i) m[i][i] = 0;
	
	for(int r = 2; r <= n; r++)
		for(int i = 1; i <= n - r +1; ++i)
		{
			//std::cout << r <<" " << i << std::endl;
			int j = i + r -1;
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for(int k = i+1; k < j; ++k)
			{
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t < m[i][j])
				{
					m[i][j] = t; s[i][j] = k;
				}
			}
		}
}

void track_back(int i, int j, int **s)
{
	if(i == j) return;
	track_back(i, s[i][j], s);
	track_back(s[i][j] + 1, j, s);
	std::cout << "multiply A "<< i <<","<<s[i][j];
	std::cout << " and A " <<(s[i][j]+1)<<","<<j<<std::endl;
}

int main(int argc, char const *argv[])
{
	std::cout << "--start\n";
	int p[]= {30, 35, 15, 5, 10, 20, 25};
	const int n = 6;
	int** m = (int**)malloc((n+1)*sizeof(int*));
	int** s = (int**)malloc((n+1)*sizeof(int*));
	for(int i = 0; i <=n; ++i)
	{
		m[i] = (int*) malloc((n+1)*sizeof(int));
		s[i] = (int*) malloc((n+1)*sizeof(int));
	}
	if(m == NULL|| s == NULL)perror("malloc failed\n");
	std::cout << "--malloc array success\n";

	matrix_chain(p, n, m, s);
	std::cout << "--finished calc multipy and start trackback\n";
	track_back(1, n, s);
	std::cout << "--free space\n";
	for(int i = 0; i <=n; ++i)
	{
		free(m[i]);
		free(s[i]);
	}
	free(s);
	free(m);
	return 0;
}