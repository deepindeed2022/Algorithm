#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX_LEN 101
int e_graph[MAX_LEN][MAX_LEN]; // 
bool book[MAX_LEN];            // 标记已经被访问过的点
static int min_dist = 0;
static std::vector<int> spath;
void shortest_path(const int cur, int dist, const int target, 
                     const int n, std::vector<int> &_spath)
{
   if (dist > min_dist)
      return;
   if (cur == target)
   {
      if (dist < min_dist)
      {
         min_dist = dist;
         spath    = _spath;
      }
      return;
   }

   for (int i = 1; i <= n; ++i)
   {
      if (e_graph[cur][i] != -1 && !book[i])
      {
         book[i] = true;
         _spath.push_back(i);
         shortest_path(i, dist + e_graph[cur][i], target, n, _spath);
         book[i] = false;
         _spath.pop_back();
      }
   }
}
// 注意：
// 无向图的表示中，初始化要对两条边同时初始化
// 有向图中只需要对其中一条边进行初始化即可
// 
int main(int argc, char const *argv[])
{
   // desclearation the parameter
   FILE *f;
   f = fopen("shorted_path.txt", "r");
   int V, E;

   memset(e_graph, -1, MAX_LEN * MAX_LEN * sizeof(int));
   // scanf the input data
   fscanf(f, "%d %d", &V, &E);
   for (int i = 1; i <= V; ++i) e_graph[i][i] = 0;

   int s, e, w;
   for (int i = 1; i <= E; ++i)
   {
      fscanf(f, "%d %d %d", &s, &e, &w);
      e_graph[s][e] = w;
      //e_graph[e][s] = w;
   }

   // confirm the input value
   assert(E < MAX_LEN && V < MAX_LEN);


   for (int i = 1; i <= V; i++)
   {
      for (int j = 1; j <= V; j++) printf("%d ", e_graph[i][j]);
      printf("\n");
   }

   // INIT PARAMETER
   memset(book, false, MAX_LEN * (sizeof(bool)));
   book[1] = true;

   std::vector<int> _spath;
   _spath.push_back(1);

   int dist = 0;
   min_dist = INT_MAX;

   shortest_path(1, dist, V, V, _spath);

   // OUTPUT RESULT
   printf("V: %d  E: %d\n", V, E);
   printf("start: %d target: %d ", 1, V);
   printf("min path is %d\n", min_dist);
   for (int i = 0; i < spath.size() - 1; ++i)
   {
      printf("(%d)--%d-->", spath[i], e_graph[spath[i]][spath[i + 1]]);
   }
   printf("(%d)\n", spath[spath.size() - 1]);
   return 0;
}