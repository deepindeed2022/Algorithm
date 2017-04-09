#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using std::vector;
const static int MAX_LEN = 101;
const static int MAX_VAL = 10000;
// 我们使用一维数组进行构建堆
int *h;   // 构建最小堆,其中存储的为node的标志
int *pos; // 存储每个node在最小堆中的位置
int size; // 堆的大小

int *dist; // 存储最小生成树到所有点的距离，其中各点的值为构建堆的过程中判别依据

#define Alloc_Heap(V)                                                          \
   book = (bool *)malloc(sizeof(bool) * (V));                                  \
   dist = (int *)malloc(sizeof(int) * (V));                                    \
   h    = (int *)malloc(sizeof(int) * (V));                                    \
   pos  = (int *)malloc(sizeof(int) * (V))

#define Free_Heap()                                                            \
   free(dist);                                                                 \
   free(h);                                                                    \
   free(pos);                                                                  \
   free(book)

//  交换堆中两个点之间的信息
void swap(int x, int y)
{
   if (x == y)
      return;
   int t     = h[x];
   h[x]      = h[y];
   h[y]      = t;
   t         = pos[h[x]];
   pos[h[x]] = pos[h[y]];
   pos[h[y]] = t;
}
// 从i节点向下调整堆
void minheap_shiftdown(int i)
{
   int t, flag = 0;
   while (i * 2 <= size && flag == 0)
   {
      if (dist[h[i]] > dist[h[i << 1]])
         t = i << 1;
      else
         t = i;
      if (i * 2 + 1 <= size)
      {
         if (dist[h[t]] > dist[h[i * 2 + 1]])
         {
            t = i * 2 + 1;
         }
      }
      if (t != i)
      {
         swap(t, i);
         i = t;
      }
      else
         flag = 1;
   }
}
// 从i节点向上调整堆
void minheap_shiftup(int i)
{
   bool flag = false;
   if (i == 1)
      return;
   while (i != 1 && !flag)
   {
      if (dist[h[i]] < dist[h[i / 2]])
         swap(i, i / 2);
      else
         flag = true;

      i = i / 2;
   }
}
int minheap_pop()
{
   int t     = h[1];
   pos[t]    = 0;
   h[1]      = h[size];
   pos[h[1]] = 1;
   size--;
   minheap_shiftdown(1);
   return t;
}



int main(int argc, char const *argv[])
{
   int V, E;
   bool *book;
   // 使用邻接表进行存储图
   int *first; // 存储第i个顶点的第一条边的编号总长度为V
   int *next;  // 存储编号为i的边的下一条的编号，有向图总长度为E， 无向图2E
   int *u, *v, *w;

#define Alloc_Edge(V, E)                                                       \
   first = (int *)malloc(sizeof(int) * (V));                                   \
   next  = (int *)malloc(sizeof(int) * (E));                                   \
   u     = (int *)malloc(sizeof(int) * (E));                                   \
   v     = (int *)malloc(sizeof(int) * (E));                                   \
   w     = (int *)malloc(sizeof(int) * (E))

#define Free_Edge()                                                            \
   free(first);                                                                \
   free(next);                                                                 \
   free(u);                                                                    \
   free(v);                                                                    \
   free(w)

   FILE *f;
   f = fopen("minimal_spanning_tree.txt", "r");
   if (f == NULL)
      perror("Error opening file");
   fscanf(f, "%d %d", &V, &E);

   Alloc_Edge(V + 1, 2 * E + 1);

   for (int i = 1; i <= E; ++i)
   {
      fscanf(f, "%d %d %d", &u[i], &v[i], &w[i]);
   }
   for (int i = E + 1; i <= 2 * E; ++i)
   {
      u[i] = v[i - E];
      v[i] = u[i - E];
      w[i] = w[i - E];
   }

   Alloc_Heap(V + 1);

   memset(first, -1, sizeof(bool) * (V + 1));

   // 初始化first
   for (int i = 1; i <= V; ++i) first[i] = -1;
   for (int i = 1; i <= 2 * E; ++i)
   {
      next[i]     = first[u[i]];
      first[u[i]] = i;
   }

   memset(book, false, sizeof(bool) * (V + 1));
   // prim核心部分开始
   book[1] = true; // 用book标志一个顶点是否已经被加入了生成树中
   int sum   = 0;
   int count = 1;
   // 初始化dist数组
   dist[1] = 0;
   for (int i = 2; i <= V; ++i) dist[i] = MAX_VAL;

   int k = first[1];
   while (k != -1)
   {
      dist[v[k]] = w[k];
      k          = next[k];
   }
   // 初始化堆
   size = V;
   for (int i = 1; i <= size; h[i] = pos[i] = i++)
      ;
   for (int i = size / 2; i >= 1; minheap_shiftdown(i--))
      ;

   //弹出堆顶元素
   minheap_pop();
   while (count < V)
   {
      // 查找距离当前树最小的点
      int j = minheap_pop();

      book[j] = true;
      count++;
      sum += dist[j];

      // 更新各点到树的距离
      k = first[j]; // 获取顶点i的所有相连边的头
      while(k != -1)
      {
         if(!book[v[k]] && dist[v[k]] > w[k])
         {
            dist[v[k]] = w[k];
            minheap_shiftup(pos[v[k]]);
         }
         k = next[k];
      }
   }
   printf("sum:%d\n", sum);


   Free_Heap();
   Free_Edge();
   return 0;
}