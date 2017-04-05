# 图的表示方法

## 图的邻接矩阵存储方法

二维数组中第i行第j列表示顶点i到顶点j是否有边。1表示有边，-1或者无穷表示无边，激励我们将自己到自己设为0.如果表示的为无向图，则矩阵为对称矩阵。
graph_adjacent_1.txt中先输入有V个顶点有E条边
然后接下来E行为边的两个顶点。
5 5
1 2
1 3
1 5
2 4
3 5

## 图的邻接表的存储方法
邻接表是图的一种链式存储结构。对图的每个顶点建立一个单链表（n个顶点建立n个单链表），第i个单链表中的结点包含顶点Vi的所有邻接顶点。又称链接表。适用于**稀疏图**的存储。

```cpp
int u[MAX_LEN];
int v[MAX_LEN];
int w[MAX_LEN];
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

void access_graph(const int V)
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
```
其中Dijstra算法使用堆进行选择最小距离，基于连接表的存储方式的时间复杂度为$O((V+E)logV)$ ,如果[基于邻接矩阵的表示方法](https://github.com/cwlseu/Algorithm/blob/master/aha/ch6/dijkstra.cpp), 时间复杂度为$O(V^2)$. 当图比较稀疏的时候，E << V^2, 这个时候$O((V+E)logV)$比$O(V^2)$小得多。

# 遍历方法

**深度优先遍历**的主要思想就是首先以一个未被访问过的顶点作为起始出发点，沿着当前顶点的边走到未被访问过的顶点：当没有未被访问过的顶点的是偶，则回到上一个顶点，继续试探访问别的顶点，知道所有的顶点都被访问过。显然，深度优先遍历是沿着图的某一条分支遍历直到末端，然后回溯，再沿着另一条进行同样的遍历，直到所有的顶点都被访问过为止。

**广度优先遍历**更加适用于所有边的权值相同的情况。
