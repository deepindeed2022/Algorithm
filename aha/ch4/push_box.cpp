#include <cassert>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <stdio.h>
using namespace std;
// 上下左右进行轮询辅助
int next_[4][2] = {
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

//迷宫
static std::vector<std::vector<bool>> maze;
//迷宫的长宽
static int maze_h, maze_w;
//标记是否走过了
static std::vector<std::vector<bool>> book;
// 初始位置和目标位置
static int startx, starty;
static int p, q; //目标的位置
static int boxx, boxy;
// 记录最小路径长度
static int min_step = INT_MAX;

static std::vector<std::pair<int, int>> min_path;

static int total = 0;
/**
 * 走迷宫
 * @param x, y 当前的位置坐标
 * @param step 当前走了多少步了
 * @return
 **/
void dfs(int x, int y, int step, std::vector<std::pair<int, int>> &path, 
        const int endx, const int endy)
{

   if (x == endx && endy == y)
   {
      //std::cout << step << std::endl;
      min_step = step < min_step ? step : min_step;
      min_path = path;
      return;
   }
   // 进行合理性剪枝, 当前步骤已经比最小步骤多了的话，这种情况我们可以不考虑了
   if (step >= min_step)
      return;
   int tx, ty;
   for (int i = 0; i < 4; ++i)
   {
      tx = x + next_[i][0];
      ty = y + next_[i][1];
      if (!inMaze(tx, ty, maze_w, maze_h))
         continue;

      if (maze[tx][ty] && !book[tx][ty])
      {
         path.push_back(std::make_pair(tx, ty));
         book[tx][ty] = true;
         dfs(tx, ty, step + 1, path, endx, endy);
         path.pop_back();
         book[tx][ty] = false;
      }
   }
}



int main(int argc, char const *argv[])
{
   // 读取数据
   //ifstream cin("push_box_dfs.txt");
   // ofstream cout("result.txt");
   scanf("%d", &maze_w);
   scanf("%d", &maze_h);

   //cin >> maze_w >> maze_h;

   maze.resize(maze_w, std::vector<bool>(maze_h, false));

   book.resize(maze_w, std::vector<bool>(maze_h, false));


   char c;
   for (int i = 0; i < maze_w; ++i)
      for (int j = 0; j < maze_h; ++j)
      {
         //cin >> c;
         c = getchar();
         switch(c){
            case '0':
               boxx = i; boxy = j;
               maze[i][j] = true;
               break;
            case 'S':
               startx = i; starty = j;
               maze[i][j] = true;
               break;
            case 'E':
               p = i; q = j;
               maze[i][j] = true;
               break;
            case '#':
               maze[i][j] = false;
               break;
            case '.':
               maze[i][j] = true;
               break;
            default:
               maze[i][j] = false;
         }

      }

   //检查输入
   // assert(q < maze_h && q>= 0);
   // assert(p < maze_w && p >= 0);

   // cout << " startx:" << startx << " starty: " << starty << std::endl;
   // cout << " boxx:" << boxx << " boxy: " << boxy << std::endl;
   // cout << " endx:" << p << " endy: " << q << std::endl;
   // cout << " maze_h:" << maze_h << " maze_w: " << maze_w << std::endl;

   
   std::vector<std::pair<int, int>> path;
   path.clear();

   path.push_back(std::make_pair(startx, starty));
   book[startx][starty] = true;
   //book.resize(maze_h, std::vector<bool>(maze_w, false));
   // 走迷宫
   dfs(startx, starty, 0, path, boxx, boxy);
   // //结果输出
   total = min_step;
   // cout <<" min_step:" << min_step << std::endl;

   //
   book.resize(maze_h, std::vector<bool>(maze_w, false));
   book[boxx][boxy] = true;
   path.clear();
   path.push_back(std::make_pair(boxx, boxy));
   min_step = INT_MAX;
   dfs(boxx, boxy, total, path, p, q);

   //cout << min_step << std::endl;
   printf("%d\n", min_step+1);

   return 0;
}