#include <queue>
#include <utility>

#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Point
{
 public:
   Point(): x(0), y(0){}
   Point(int _x, int _y): x(_x), y(_y){}

 public:
   int x;
   int y;
};
#define MAX_LEN 20
// 上下左右进行轮询辅助
static int next_[4][2] = {
   {0, 1},  //向右走
   {1, 0},  //向下走
   {0, -1}, //向左走
   {-1, 0}  //向上走
};
//判断坐标是否合法
bool inMaze(int tx, int ty, int maze_w, int maze_h)
{
   return tx >= 0 && tx < maze_w && ty >= 0 && ty < maze_h;
}

int getsum(int i, int j, const char map[MAX_LEN][MAX_LEN])
{
   int sum = 0;
   int x, y;
   x = i, y = j;
   while (map[x][y] != '#')
   {
      sum += map[x--][y] == 'G' ? 1 : 0;
   }

   x = i, y = j;
   while (map[x][y] != '#') sum += map[x++][y] == 'G' ? 1 : 0;

   x = i, y = j;
   while (map[x][y] != '#') sum += map[x][y--] == 'G' ? 1 : 0;

   x = i, y = j;
   while (map[x][y] != '#') sum += map[x][y++] == 'G' ? 1 : 0;

   return sum;
}

bool book[MAX_LEN][MAX_LEN]; //标记数组, 记录是否已经访问过了
char map[MAX_LEN][MAX_LEN];  // 游戏的地图

void dfs(const int startx, const int starty, const int n, const int m, 
      int &max_enemy, Point &max_site)
{
   int sum = getsum(startx, starty, map);
   if (sum > max_enemy)
   {
      max_site.x = startx;
      max_site.y = starty;
      max_enemy  = sum;
   }
   int tx, ty;
   for (int i = 0; i < 4; ++i)
   {
      tx = startx + next_[i][0];
      ty = starty + next_[i][1];
      if (!inMaze(tx, ty, n, m))
         continue;
      if (map[tx][ty] == '.' && !book[tx][ty])
      {
         book[tx][ty] = true;
         dfs(tx, ty, n, m, max_enemy, max_site);
      }
   }
}

int main(int argc, char const *argv[])
{
   // desclearation the parameter
   FILE *f;
   f = fopen("game.txt", "r");

   int m, n;
   int startx, starty;
   memset(book, false, MAX_LEN * MAX_LEN * sizeof(bool));
   // scanf the input data
   fscanf(f, "%d %d %d %d", &n, &m, &startx, &starty);
   for (int i = 0; i < n; ++i)
   {
      fscanf(f, "%s", map[i]);
   }

   // confirm the input value
   assert(n < MAX_LEN && m < MAX_LEN);
   assert(startx < n && startx >= 0);
   assert(starty < m && starty >= 0);

   Point max_site(startx, starty);
   int max_enemy;
   dfs(startx, starty, n, m, max_enemy, max_site);

   // out put result
   printf("start:(%d, %d)\nmap as follwing:\n", startx, starty);

   for (int i = 0; i < n; ++i) printf("%s\n", map[i]);
   printf(" The bomb should be set: (%d, %d)\n\
            Kill %d enemies\n",
          max_site.x, max_site.y, max_enemy);
   return 0;
}