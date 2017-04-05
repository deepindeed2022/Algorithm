#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LEN 101
static const int MAX_VAL = 1000;
int u[MAX_LEN];
int v[MAX_LEN];
int w[MAX_LEN];
int dist[MAX_LEN];

// 读入边的格式为u v w
// weight(u, v) = w
void read_graph(FILE *f, int E)
{
   for (int i = 1; i <= E; i++)
   {
      fscanf(f, "%d %d %d", &u[i], &v[i], &w[i]);
   }
}

void print_graph(const int E)
{
   for (int i = 1; i <= E; i++)
   {
      printf("w(%d,%d) = %d\n", u[i], v[i], w[i]);
   }
}
void bellman_ford(const int start, const int V, const int E)
{
   // 初始化距离向量
   for(int i = 1; i <= V; ++i) dist[i] = MAX_VAL;
   dist[start] = 0;
   for (int k = 1; k <= V - 1; k++)
   {
      for(int i = 1; i <= E; ++i)
      {
         if(dist[v[i]] > dist[u[i]] + w[i])
         {
            printf("w(%d, %d)=%d && dist[%d]=%d => ", u[i], v[i], w[i], u[i], dist[u[i]]);
            printf("dist[%d]=%d->",v[i], dist[v[i]]);
            dist[v[i]] = dist[u[i]] + w[i];
            printf("dist[%d]=%d\n",v[i], dist[v[i]]);
         }
      }
   }
}
int main(int argc, char const *argv[])
{
   // desclearation the parameter
   FILE *f;
   f = fopen("bellman_ford.txt", "r");
   int V, E;
   int start = 1;
   // scanf the input data
   fscanf(f, "%d %d", &V, &E);
   read_graph(f, E);
   bellman_ford(start, V, E);
   print_graph(V);
   printf("\nThe shortest path:\n");
   for(int i = 1; i <=V; ++i)
      printf("min(%d, %d) = %d\n", start, i, dist[i]);

   return 0;
}