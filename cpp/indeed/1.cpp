#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cassert>
const static int MAX_LEN = 1001;
bool square[MAX_LEN][MAX_LEN];
// 上下左右进行轮询辅助
int next[4][2] = {
   {0, 1},  //向右走 1
   {1, 0},  //向下走 2
   {0, -1}, //向左走 3
   {-1, 0}  //向上走 0
};
int N, M = 0;

int main(int argc, char const *argv[])
{
	memset(square, true, MAX_LEN*MAX_LEN*sizeof(bool));
	

	// FILE* f;
	// f = fopen("1.txt", "r");
	// assert(fscanf(f, "%d %d", &N, &M));
	//memset(square, true, MAX_LEN*MAX_LEN*sizeof(bool));
	assert(scanf("%d %d", &N, &M));
	int curx = 1;
	int cury = 1;
	if(M == 1) 
	{
		printf("%d %d\n", curx, cury);
		return 0;
	}
	else
	{
		int offx = 1;
		int offy = 0;
		square[curx][cury] = false;
		for(int turn = 1; turn < M; turn++)
		{
			switch (turn % 4)
			{
			case 1:
				offx = next[0][0];
				offy = next[0][1];
				while(cury < N && square[curx+offx][cury+offy])
				{
					curx += offx;
					cury +=	offy;
				}
				square[curx][cury] = false;
				printf("%d %d\n", curx, cury);
				break;
			case 2:
				offx = next[1][0];
				offy = next[1][1];
				while(curx < N && square[curx+offx][cury+offy])
				{
					curx += offx;
					cury +=	offy;
				}
				square[curx][cury] = false;
				printf("%d %d\n", curx, cury);
				break;
			case 3:
				offx = next[2][0];
				offy = next[2][1];
				while(cury > 1 && square[curx+offx][cury+offy])
				{
					curx += offx;
					cury +=	offy;
				}
				square[curx][cury] = false;
				printf("%d %d\n", curx, cury);
				break;	
			case 0:
				offx = next[3][0];
				offy = next[3][1];
				while(curx > 1 && square[curx+offx][cury+offy])
				{
					curx += offx;
					cury +=	offy;
				}
				square[curx][cury] = false;
				printf("%d %d\n", curx, cury);
				break;	
			default:
				exit(1);
			}
			square[curx][cury] = false;
		}
	}
	printf("%d %d\n", cury, curx);
	return 0;
}