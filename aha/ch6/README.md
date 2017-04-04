## Floyd-warshall
Floyd-Warshall算法,中文亦称弗洛伊德算法,是解决**任意两点**间的最短路径的一种算法,可以正确处理有向图或负权（**但不可存在负权回路**)的最短路径问题,
同时也被用于计算有向图的传递闭包。Floyd-Warshall算法的时间复杂度为$O(N^3)$，空间复杂度为$O(N^{2})$。

### Floyd-Warshall算法的原理是动态规划
设 $D_{i,j,k}$为从$i$到$j$的只以$(1..k)$集合中的节点为中间节点的最短路径的长度。
若最短路径经过点k,则 $D_{i,j,k}=D_{i,k,k-1}+D_{k,j,k-1}$；
若最短路径不经过点k,则 $D_{i,j,k}=D_{i,j,k-1}$。
因此，$D_{i,j,k}=min(D_{i,j,k-1},D_{i,k,k-1}+D_{k,j,k-1})$。
在实际算法中,为了节约空间,可以直接在原来空间上进行迭代,这样空间可降至二维。

### 伪代码

```python
"""
let dist be a |V|x|V| array of minimum distance initialized to infinity
其中dist[i][j]表示由点i到点j的代价，当其为 ∞ 表示两点之间没有任何连接
"""
# init the graph
for v in vertex:
    dist[v][v] = 0
for edge(u, v) in edge:
    dist[u][v] = w(u, v)

# start the main algorithm
for k range(1,|V|):
    for i range(1, |V|):
        for j range(1, |V|):
            if dist[i][j] > dist[i][k] + dist[k][j]: 
                dist[i][j] = dist[i][k] + dist[k][j]
            endif
        endfor
    endfor
endfor
```

### 为什么不能解决带有"负权回路"的图，因为带有负权回路的图没有最短路径。因为1->2->3->1->2->3->1->2->3，每次绕一次就减少1, 永远都找不到最短路径。

## Dijkstra算法
