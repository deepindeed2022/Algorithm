#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LEN 101
static const int MAX_VAL = 1000;
int u[MAX_LEN];
int v[MAX_LEN];
int w[MAX_LEN];
int dist[MAX_LEN];

int first[MAX_LEN]; // 存储第i个顶点的第一条边的编号总长度为V
int next[MAX_LEN];  // 存储编号为i的边的下一条的编号总长度为E
// 读入边的格式为u v w
// weight(u, v) = w
void read_graph(FILE *f, int E)
{
   memset(first, -1, sizeof(first));
   for (int i = 1; i <= E; i++)
   {
      fscanf(f, "%d %d %d", &u[i], &v[i], &w[i]);
      //关键
      next[i]     = first[u[i]];
      first[u[i]] = i;
   }
}

void print_graph(const int V)
{
   for (int i = 1; i <= V; i++)
   {
      int k = first[i];
      while (k != -1)
      {
         printf("w(%d,%d) = %d\n", u[k], v[k], w[k]);
         k = next[k];
      }
   }
}
void dijkstra(const int start, const int V)
{
   // 初始化距离向量
   for(int i = 1; i <= V; ++i) dist[i] = MAX_VAL;
   dist[start] = 0;
   int k = first[start]; // 存储第i个顶点的第一条边的编号
   while(k != -1)
   {     
      dist[v[k]] = w[k];
      k = next[k]; // 存储编号为i的边的下一条的编号
   }
   // 初始化标记数组
   bool* book;
   book = (bool*)malloc((V+1)*(sizeof(bool)));
   memset(book, false, sizeof(bool)*(V+1));
   // book为0表示定点在未知最短路径的顶点集合Q中，
   // 为true表示在最短路径定点集合P中
   book[start] = true;

   for (int i = 1; i <= V; i++)
   {
      //在未知最短路径的定点集合中选择到原点start最近的顶点u
      int min = MAX_VAL;
      int uu;
      for(int j = 1; j <= V; ++j)
      {
         if(min > dist[j] && !book[j])
         {
            min = dist[j];
            uu = j;
         }
      }
      
      // 将点u加入到P集合中
      book[uu] = true;
      // 获取存储第i个顶点的第一条边的编号
      k = first[uu];
      while (k != -1)
      {
         if(w[k] < MAX_VAL)
         {
            if(dist[v[k]] > dist[u[k]] + w[k])
               dist[v[k]] = dist[u[k]] + w[k];
         }
         k = next[k];
      }
   }
   free(book);
}
int main(int argc, char const *argv[])
{
   // desclearation the parameter
   FILE *f;
   f = fopen("dijkstra.txt", "r");
   int V, E;
   int start = 1;
   // scanf the input data
   fscanf(f, "%d %d", &V, &E);
   read_graph(f, E);
   dijkstra(start, V);
   print_graph(V);
   printf("\nThe shortest path:\n");
   for(int i = 1; i <=V; ++i)
      printf("min(%d, %d) = %d\n", start, i, dist[i]);

   return 0;
}