## Kruskal最小生成树算法

该算法中包含对边的排序，时间复杂度为O(ElogE)，在E条边中找出V-1条边的时间复杂度为O(ElogV)所以该算法的时间复杂度为O(ElogE+ElogV)。通常情况下E比V大得多，所以最后的时间复杂度为O(ElogE)

<https://github.com/cwlseu/Algorithm/blob/master/aha/ch8/kruskal_minimal_spanning_tree.cpp>

## Prim 算法

* 从任意一个顶点开发构造生成树，假设从1号顶点开始。首先将顶点1加入生成树中，用一个一维数组book来标记那些顶点已经加入了生成树
* 用数组dist记录生成树到各个顶点的距离。最初生成树中只有1号顶点。有直连边的时候，dist存储的就是一号顶点到该点的权值，没有直连边的时候为Infinity
* 从数组dist中选出离生成树最近的点（假设该点为j），加入到生成树中。再以j为中间点，更新生成树到每一个非树顶点的距离。即`dist[k] > e[j][k]` 更新 `dist[k] = e[j][k]`
* 重复第三步，直到所有的节点被加入为止。

### 采用邻接矩阵表示的实现
时间复杂度为O(V^2)

```cpp
// 初始化距离矩阵
   for(int i = 1; i <= V; ++i) dist[i] =  graph[1][i];
   book[1] = true;
   int sum = 0;
   int count = 1;
   while(count < V)
   {
      // 查找距离当前树最小的点
      // 时间复杂度为O(V), 如果采用堆进行优化的话可以降到O(logV)
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
```
<github代码托管https://github.com/cwlseu/Algorithm/blob/master/aha/ch8/prim_arr_minimal_spanning_tree.cpp>

### 采用邻接表表示的方法O(ElogV)

其中推荐最小距离点的时候采用堆实现推荐，其中获取顶点元素时间为O(1)，调整堆时间为O(logV)。
调整代码实现如下:

```cpp
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
```
Prim算法关键部分如下：

```cpp
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
```
<https://github.com/cwlseu/Algorithm/blob/master/aha/ch8/prim_heap_minimal_spanning_tree.cpp>