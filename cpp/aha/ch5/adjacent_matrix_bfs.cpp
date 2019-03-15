#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using std::queue;
#define MAX_LEN 101

int e_graph[MAX_LEN][MAX_LEN]; // 游戏的地图
bool book[MAX_LEN];            // 标记已经被访问过的点
static int total_v = 0;

void bfs(const int cur, const int n, std::ostream &os = std::cout)
{
   std::queue<int> que;
   bool *book = (bool *)malloc((n + 1) * sizeof(bool));
   memset(book, false, (n + 1) * sizeof(bool));
   for(int i = 0; i < n+1; ++i)printf("%u ", book[i]);
      printf("\n");
   que.push(cur);
   book[cur] = true;
   while (!que.empty())
   {
      int head = que.front();
      os << head << " ";
      for (int i = 1; i <= n; ++i)
      {
         if (e_graph[head][i] == 1 && !book[i])
         {
            que.push(i);
            book[i] = true;
         }
      }
      que.pop();
   }
   free(book);
}
// void format_graph()
// {
//    for(int i = 0; i <)
// }
int main(int argc, char const *argv[])
{
   // desclearation the parameter
   FILE *f;
   f = fopen("graph_adjacent_2.txt", "r");
   int V, E;


   memset(e_graph, INT_MAX, MAX_LEN * MAX_LEN * sizeof(int));
   // scanf the input data
   fscanf(f, "%d %d", &V, &E);
   for (int i = 1; i <= V; ++i) e_graph[i][i] = 0;

   int start, end;
   for (int e = 1; e <= E; ++e)
   {
      fscanf(f, "%d %d", &start, &end);
      e_graph[start][end] = 1;
      e_graph[end][start] = 1;
   }
   total_v = 0;
   printf("V: %d  E: %d\n", V, E);
   // confirm the input value
   assert(E < MAX_LEN && V < MAX_LEN);
   memset(book, false, MAX_LEN * (sizeof(bool)));
   bfs(1, V, std::cout);
   return 0;
}