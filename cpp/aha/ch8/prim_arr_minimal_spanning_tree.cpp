#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using std::vector;
const static int MAX_LEN = 101;
const static int MAX_VAL = 10000;

int main(int argc, char const *argv[])
{

   FILE *f;
   f = fopen("minimal_spanning_tree.txt", "r");
   if (f == NULL) perror ("Error opening file");

   int V, E;
   int u, v, val;
   int** graph;
   int* dist;
   bool* book;
   fscanf(f, "%d %d", &V, &E);
   graph = (int**)malloc(sizeof(int*)*(V+1));
   dist = (int*)malloc(sizeof(int)*(V+1));
   book = (bool*)malloc(sizeof(bool)*(V+1));
   memset(book, false, sizeof(bool)*(V+1));
   for(int i = 0; i <= V; ++i)
   {
      graph[i] = (int*)malloc(sizeof(int)*(V+1));
      for(int j = 1; j <= V; ++j) graph[i][j] = MAX_VAL;
   }
   
   for (int i = 1; i <= E; ++i)
   {
      fscanf(f, "%d %d %d", &u, &v, &val);
      graph[u][v] = graph[v][u] = val;
   }
   // 初始化距离矩阵
   for(int i = 1; i <= V; ++i) dist[i] =  graph[1][i];
   book[1] = true;
   int sum = 0;
   int count = 1;
   while(count < V)
   {
      // 查找距离当前树最小的点
      int j = 0;
      int min = MAX_VAL;
      for(int i = 1; i <= V; ++i)
      {
         if(!book[i] && dist[i] < min)
         {
            min = dist[i]; j = i;
         }
      }
      book[j] = true;
      count++;
      sum += dist[j];
      // 更新各点到树的距离
      for(int k = 1; k <= V; ++k)
      {
         if(!book[k] && dist[k] > graph[j][k])
            dist[k] = graph[j][k];
      }
   }
   printf("sum:%d\n", sum);


   for(int i = 0; i <= V; ++i)
   {
      free(graph[i]);
   }
   free(graph);
   free(dist);
   free(book);
   return 0;
}