#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX_LEN 101
int e_graph[MAX_LEN][MAX_LEN]; //
bool book[MAX_LEN];            // 标记已经被访问过的点

typedef struct tNode
{
   int f;
   int x;
   int s;
   tNode(int _x, int _s, int _f)
      : x(_x)
      , s(_s)
      , f(_f)
   {
   }
   tNode(int _x, int _s)
      : x(_x)
      , s(_s)
      , f(-1)
   {
   }
} tNode;
int least_transfer(const int cur, const int target, const int n)
{
   std::queue<tNode> que;
   std::vector<tNode> path;
   que.push(tNode(cur, 0));
   path.push_back(tNode(cur, 0, -1));
   book[cur] = true;
   int flag  = false;
   while (!que.empty())
   {
      tNode head = que.front();
      for (int i = 1; i <= n; ++i)
      {
         if (e_graph[head.x][i] != -1 && !book[i])
         {
            que.push(tNode(i, head.s + 1));
            path.push_back(tNode(i, head.s + 1, head.x));
            book[i] = true;
         }
         if (que.back().x == target)
         {
            flag = true;
            break;
         }
      }

      if (flag)
         break;
      que.pop();
   }


   // 获取换乘路径
   int size = que.back().s + 1;
   std::vector<tNode> min_trans(size, tNode(-1, -1, -1));
   min_trans[size - 1] = path[path.size() - 1];
   for (int i = 1; i < size; ++i)
   {
      tNode pre = min_trans[size - i];
      bool flag = false;
      for (int j = 0; j < path.size(); ++j)
      {
         if (path[j].s + 1 == pre.s && pre.f == path[j].x)
         {
            min_trans[size - i - 1] = path[j];
            flag = true;
         }
      }
      assert(flag);
   }
   printf("translate airplane as:\n");
   for(int i = 0; i < size; ++i)
   {
      printf("cite%d -> ", min_trans[i].x);
   }
   printf("\n");
   return que.back().s;
}
// 注意：
// 无向图的表示中，初始化要对两条边同时初始化
// 有向图中只需要对其中一条边进行初始化即可
//
int main(int argc, char const *argv[])
{
   // desclearation the parameter
   FILE *f;
   f = fopen("least_transfer.txt", "r");
   int V, E;
   int start, target;
   memset(e_graph, -1, MAX_LEN * MAX_LEN * sizeof(int));
   // scanf the input data
   fscanf(f, "%d %d %d %d", &V, &E, &start, &target);
   for (int i = 1; i <= V; ++i) e_graph[i][i] = 0;

   int s, e;
   for (int i = 1; i <= E; ++i)
   {
      fscanf(f, "%d %d", &s, &e);
      e_graph[s][e] = 1;
      e_graph[e][s] = 1;
   }

   // confirm the input value
   assert(E < MAX_LEN && V < MAX_LEN);



   // INIT PARAMETER
   memset(book, false, MAX_LEN * (sizeof(bool)));

   printf("V: %d  E: %d\n", V, E);
   printf("The adjacent graph as:\n");
   for (int i = 1; i <= V; i++)
   {
      for (int j = 1; j <= V; j++) printf("%d ", e_graph[i][j]);
      printf("\n");
   }
   int min_trans = least_transfer(start, target, V);

   // OUTPUT RESULT
   printf("from cite%d to cite%d at least translate %d times.\n", start, target,
          min_trans);

   return 0;
}