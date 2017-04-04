#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>

#define MAX_LEN 101
static const int MAX_VAL = 1000;

int e_graph[MAX_LEN][MAX_LEN]; // 
int dist[MAX_LEN];

void dijkstra(const int start, const int V)
{
   // 初始化距离向量
   for(int i = 1; i <= V; ++i) dist[i] = e_graph[start][i];
   bool* book;
   book = (bool*)malloc((V+1)*(sizeof(bool)));
   memset(book, false, sizeof(bool)*(V+1));
   book[start] = true;
   // book为0表示定点在未知最短路径的顶点集合Q中，
   // 为true表示在最短路径定点集合P中
   for(int i =0; i<= V; ++i)
   {
      //在未知最短路径的定点集合中选择到原点start最近的顶点u
      int min = MAX_VAL;
      int u;
      for(int j = 1; j <= V; ++j)
      {
         if(min > dist[j] && !book[j])
         {
            min = dist[j];
            u = j;
         }
      }
      // 将点u加入到P集合中
      book[u] = true;
      // 因为u的加入，调整P中的距离情况
      for(int v = 1; v<= V; ++v)
      {
         if(e_graph[u][v]< MAX_VAL)
         {
            if(dist[v] > dist[u] + e_graph[u][v])
               dist[v] = dist[u] + e_graph[u][v];
         }
      }
   }

   free(book);
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
   f = fopen("dijkstra.txt", "r");
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
   // OUTPUT RESULT
   printf("\nV: %d  E: %d\n\n", V, E);
   printf("The orignal map:\n");
   for (int i = 1; i <= V; i++)
   {
      for (int j = 1; j <= V; j++) printf("%d ", e_graph[i][j]);
      printf("\n");
   }
   dijkstra(1, V);
   printf("\n");
   for(int i = 1; i <=V; ++i)
      printf("%d to %d min distance is %d\n", 1, i, dist[i]);
   printf("\n");
   return 0;
}