/******************************************************************************
 * @description：
 *    走迷宫问题
 * 考虑要点：
 *  1.
 拓展状态+表示状态。当前步与下一步之间如何转换，本题目中采用一个book进行记录已经走过的步骤。
 *  当前步骤与下一步至今采用重置book值的方式实现切换
 *  2. 一次搜索终止条件是什么?
 *  3. 优化：
      是否可以进行剪枝操作？判断条件是什么？

 *
 ******************************************************************************/

#include <cassert>
#include <climits>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
 #include <cstdlib>
#include "dfs_format_print.h"
using namespace std;

//迷宫
static std::vector<std::vector<bool>> maze;
//迷宫的长宽
static int maze_h, maze_w;
//标记是否走过了
static std::vector<std::vector<bool>> book;
// 初始位置和目标位置
static int startx, starty;
static int p, q; //目标的位置
// 记录最小路径长度
static int min_step = INT_MAX;
// 上下左右进行轮询辅助
static int next_[4][2] = {
   {0, 1},  //向右走
   {1, 0},  //向下走
   {0, -1}, //向左走
   {-1, 0}  //向上走
};
static std::vector<std::pair<int, int>> min_path;
//判断坐标是否合法
bool inMaze(int tx, int ty)
{
   return tx >= 0 && tx < maze_w && ty >= 0 && ty < maze_h;
}
static int total = 0;
/**
 * 走迷宫
 * @param x, y 当前的位置坐标
 * @param step 当前走了多少步了
 * @return
 **/
void dfs(int x, int y, int step, std::vector<std::pair<int, int>> &path)
{
   if (x == p && q == y)
   {
      min_step = step < min_step ? step : min_step;
      min_path = path;
      return;
   }
   // 进行合理性剪枝, 当前步骤已经比最小步骤多了的话，这种情况我们可以不考虑了
   // 直接舍弃掉，可以通过输出total进行验证
   if (step >= min_step)
      return;
   int tx, ty;
   for (int i = 0; i < 4; ++i)
   {
      tx = x + next_[i][0];
      ty = y + next_[i][1];
      if (!inMaze(tx, ty))
         continue;
      if (maze[tx][ty] && !book[tx][ty])
      {
         path.push_back(std::make_pair(tx, ty));
         book[tx][ty] = true;
         dfs(tx, ty, step + 1, path);
         path.pop_back();
         book[tx][ty] = false;
         // total ++;
      }
   }
}



int main(int argc, char const *argv[])
{
   // 读取数据

   ifstream cin("dfs_find_maze.txt");
   ofstream cout("result.txt");

   cin >> maze_h >> maze_w;
   maze.resize(maze_h, std::vector<bool>(maze_w, true));
   book.resize(maze_h, std::vector<bool>(maze_w, false));
   int c;
   for (int i = 0; i < maze_h; ++i)
      for (int j = 0; j < maze_w; ++j)
      {
         cin >> c;
         maze[i][j] = (c == 0);
      }
   cin >> startx >> starty >> p >> q;

   //检查输入
   assert(p < maze_h && p >= 0);
   assert(q < maze_w && q >= 0);
   cout << " startx:" << startx << " starty: " << starty << std::endl;
   cout << " endx:" << p << " endy: " << q << std::endl;
   cout << " maze_h:" << maze_h << " maze_w: " << maze_w << std::endl;
   std::vector<std::pair<int, int>> path;
   path.clear();
   path.push_back(std::make_pair(startx, starty));
   // 走迷宫
    dfs(startx, starty, 0, path);
    //结果输出
    cout <<" min_step:" << min_step << std::endl << " step list:\n  ";
    for(int  i = 0; i < min_path.size() -1; ++i)
        cout <<"(" <<min_path[i].first << " " << min_path[i].second<<") -> ";
    cout <<"(" <<min_path[min_path.size() -1].first << " " << min_path[min_path.size() -1].second<<")";
    cout << std::endl;
    //cout << total << std::endl;
    cout << " Format result:\n";
    format_path(min_path, maze_w, maze_h, cout);
    return 0;
}