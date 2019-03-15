#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX_LEN 101
#define MAX_VAL 1000
int e_graph[MAX_LEN][MAX_LEN]; // 

void floyd_warshall(const int V)
{
   for(int k = 1; k <= V; ++k)
      for(int i = 1; i<= V; ++i)
         for(int j = 1; j <= V; ++j)
            if(e_graph[i][j] > e_graph[i][k] + e_graph[k][j])
               e_graph[i][j] = e_graph[i][k] + e_graph[k][j];
}
void init_graph(int e[][MAX_LEN], const int n, const int value)
{
   for(int i = 0; i <= n; i++)
   for(int j = 0; j <= n; j++)
      e[i][j] = value;
}
// 注意：
// 无向图的表示中，初始化要对两条边同时初始化
// 有向图中只需要对其中一条边进行初始化即可
// 
int main(int argc, char const *argv[])
{
   // desclearation the parameter
   FILE *f;
   f = fopen("floyd_warshall.txt", "r");
   int V, E;

   // scanf the input data
   fscanf(f, "%d %d", &V, &E);
   init_graph(e_graph, V, MAX_VAL);
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
   printf("The orignal map:\n");
   for (int i = 1; i <= V; i++)
   {
      for (int j = 1; j <= V; j++) printf("%d ", e_graph[i][j]);
      printf("\n");
   }
   floyd_warshall(V);

   // OUTPUT RESULT
   printf("\nV: %d  E: %d\n\n", V, E);

   for(int i = 1; i <= V; ++i)
   {
      for(int j = 1; j <= V; ++j)
         printf("%d ", e_graph[i][j]);
      printf("\n");
   }
   return 0;
}