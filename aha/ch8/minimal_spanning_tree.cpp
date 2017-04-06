#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using std::vector;

typedef struct tEdge
{
   int u;
   int v;
   int val;
   tEdge()
      : u(-1)
      , v(-1)
      , val(0)
   {
   }
   tEdge(int _u, int _v, int _val)
      : u(_u)
      , v(_v)
      , val(_val)
   {
   }
} tEdge;
static const int MAX_LEN = 101;

bool comp_edge(tEdge e1, tEdge e2) { return e1.val < e2.val; }

tEdge edges[MAX_LEN];
int find[MAX_LEN];

inline void init(int* f, const int n) 
{
   for(int i = 1; i <= n; ++i) f[i] = i;
}
int getfather(int v)
{
   // 采用递归方式实现
   // 每次在函数返回的时候，将
   if(find[v] == v)
      return v;
   find[v] = getfather(find[v]);
   return find[v];
}
bool merge(int v, int u)
{
   if(v > u) return merge(u, v);
   int t1, t2;
   t1 = getfather(v);
   t2 = getfather(u);
   if(t1 != t2)
   {
      find[t2] = t1;// 靠左原则，左边的变成右边的boss
      return true;
   }
   return false;
}
int main(int argc, char const *argv[])
{

   FILE *f;
   f = fopen("minimal_spanning_tree.txt", "r");
   if (f == NULL) perror ("Error opening file");

   int V, E;
   int u, v, val;
   int sum = 0; // 最小生成树的花费
   int count_v = 0;

   fscanf(f, "%d %d", &V, &E);
   for (int i = 1; i <= E; ++i)
   {
      fscanf(f, "%d %d %d", &u, &v, &val);
      edges[i] = tEdge(u, v, val);
   }
   std::vector<tEdge> edgev(edges+1, edges+E+1);
   std::sort(edgev.begin(), edgev.end(), comp_edge);
   init(find, V);
   // kruskal 算法
   // 从小到大枚举每一条边
   for(int i = 0; i < E; ++i)
   {
      // 判断两个顶点是否已经联通，是否在一个集合里
      if(merge(edgev[i].u, edgev[i].v))
      {
         count_v++;
         sum += edgev[i].val;
      }
      // 选择v - 1条边即可
      if(count_v == V - 1) break;
   }
   // for(int i = 1 ; i <= V; ++i) printf("%d ", find[i]);
   printf("\n");
   printf("总共要花费银票是： %d\n", sum);
   return 0;
}