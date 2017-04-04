#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX_LEN 101

int e_graph[MAX_LEN][MAX_LEN]; // 游戏的地图
bool book[MAX_LEN];            // 标记已经被访问过的点
static int total_v = 0;

void dfs(const int cur, bool book[MAX_LEN], const int n, std::ostream &os = std::cout)
{
   os << cur << " ";
   total_v++;
   book[cur] = true;
   if (total_v == n) return;
   for (int i = 1; i <= n; ++i)
   {
      if (e_graph[cur][i] == 1 && !book[i])
      {
         book[i] = true;
         dfs(i, book, n, os);
      }
   }
   return;
}
// void format_graph()
// {
//    for(int i = 0; i <)
// }
int main(int argc, char const *argv[])
{
   // desclearation the parameter
   FILE *f;
   f = fopen("graph_adjacent_1.txt", "r");
   int V, E;
   int i, j;

   memset(e_graph, INT_MAX, MAX_LEN * MAX_LEN * sizeof(int));
   // scanf the input data
   fscanf(f, "%d %d", &V, &E);
   for (int i = 1; i <= V; ++i) e_graph[i][i] = 0;

   for (int i = 1; i <= E; ++i)
   {
      fscanf(f, "%d %d", &i, &j);
      e_graph[i][j] = 1;
      e_graph[j][i] = 1;
   }
   total_v = 0;
   printf("V: %d  E: %d\n", V, E);
   // confirm the input value
   assert(E < MAX_LEN && V < MAX_LEN);
   memset(book, false, MAX_LEN * (sizeof(bool)));
   dfs(1, book, V, std::cout);
   return 0;
}