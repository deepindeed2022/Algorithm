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

#include <algorithm>
#include <cassert>
#include <climits>
#include <fstream>
#include <iostream>
#include <queue>

#include "dfs_format_print.h"
#include <cstdlib>
#include <utility>
#include <vector>
using namespace std;

//迷宫
static std::vector<std::vector<bool> > maze;
//迷宫的长宽
static int maze_h, maze_w;
//标记是否走过了
static std::vector<std::vector<bool> > book;
// 初始位置和目标位置
static int startx, starty;
static int p, q; //目标的位置

struct tNode
{
   int x; // 记录节点的位置x
   int y; // 记录节点的位置y
   int f; // 记录父亲节点的位置
   int s; // 记录步数
};
/**
 * x, y : 起始节点的位置
 * p, q : 目标节点
 * que: 记录访问节点的顺序
 **/
void bfs(int x, int y, int p, int q, std::vector<tNode> &que)
{
   int hidx = 0;
   int flag = false;
   int tx, ty;
   while (hidx < que.size())
   {
      struct tNode head = que[hidx];
      // 进行周边扫描
      for (int i = 0; i < 4; ++i)
      {
         tx = head.x + next_[i][0];
         ty = head.y + next_[i][1];
         if (!inMaze(tx, ty, maze_w, maze_h))
            continue;
         // 如果满足条件，就将节点添加到队列中
         if (maze[tx][ty] && !book[tx][ty])
         {
            struct tNode node = {tx, ty, hidx, head.s + 1};
            que.push_back(node);
            book[tx][ty] = true;
            // total ++;
         }
         if (tx == p && ty == q)
         {
            flag = true;
            break;
         }
      }
      if (flag)
         break;
      hidx++;
   }
}
void path_gen(const std::vector<tNode> &que, std::vector<std::pair<int, int> > &path)
{
   struct tNode node = que[que.size() - 1];
   while (node.f != -1)
   {
      path.push_back(std::make_pair(node.x, node.y));
      node = que[node.f];
   }
   path.push_back(std::make_pair(node.x, node.y));
   std::reverse(path.begin(), path.end());
}
int main(int argc, char const *argv[])
{
   // 读取数据
   ifstream cin("dfs_find_maze.txt");
   // ofstream cout("result.txt");
   // 读取棋盘大小
   cin >> maze_h >> maze_w;
   maze.resize(maze_h, std::vector<bool>(maze_w, true));
   book.resize(maze_h, std::vector<bool>(maze_w, false));
   // 声明临时变量，用来输入数据
   int c;
   for (int i = 0; i < maze_h; ++i)
      for (int j = 0; j < maze_w; ++j)
      {
         cin >> c;
         maze[i][j] = (c == 0);
      }
   // 输入起始位置和目标位置
   cin >> startx >> starty >> p >> q;

   //输入检查输入
   assert(p < maze_h && p >= 0);
   assert(q < maze_w && q >= 0);
   cout << " startx:" << startx << " starty: " << starty << std::endl;
   cout << " endx:" << p << " endy: " << q << std::endl;
   cout << " maze_h:" << maze_h << " maze_w: " << maze_w << std::endl;

   // 用来作为中间存放队列
   std::vector<tNode> allnode;
   allnode.clear();
   
   allnode.push_back((struct tNode){startx, starty, -1, 0});
   
   // 走迷宫
   bfs(startx, starty, p, q, allnode);

   std::vector<std::pair<int, int> > path;
   path_gen(allnode, path);
   //结果输出
   cout << " min_step:" << (*allnode.rbegin()).s << std::endl
        << " step list:\n  ";
   for (int i = 0; i < path.size() - 1; ++i)
      cout << "(" << path[i].first << " " << path[i].second << ") -> ";
   cout << "(" << path[path.size() - 1].first << " "
        << path[path.size() - 1].second <<")" << std::endl;
   format_path(path, maze_w, maze_h, cout);
   return 0;
}