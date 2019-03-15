#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>


const int INF=0x3f3f3f3f;
const int MAXN=100005;
int dist[MAXN];
bool vis[MAXN];
int n;

struct Edge
{
    int v;
    int cost;
    Edge(int _v=0, int _cost=0):v(_v), cost(_cost){}
};

struct Node
{
    char id;
    int weight;
    Node(char _id=0, int _weight=0):id(_id), weight(_weight){}
};


std::vector<Edge> E[MAXN];

void dfs(int start)//点的编号从start开始
{

    vis[start]=true;
    for(int i=0;i<E[start].size();i++)
    {
        int v=E[start][i].v;
        int cost=E[start][i].cost;
        if(vis[v]) continue;
        dist[v]=dist[start]+cost;
        dfs(v);
    }
}

int main()
{
    memset(vis, false ,sizeof(vis));

    std::cin >> n;//定点个数。
    cout << n << "个节点" << endl;

    for(int i=1;i<=n;i++) dist[i] =-INF;
    vector<Node> Nodes(n);

    for(int i = 0; i < n; i++){
        char character;
        int id, weight;
        std::cin >> character >> weight;
        id = (int)character - 65;
        //cout<<"id = "<<id<<endl;
        Nodes[id] = (Node(character, weight));
    }
    
    int e;
    std::cin >> e;
    cout<<e<<"条路径"<<endl;

    //e=n-1;
    for(int i=1;i<=n;i++) E[i].clear();
    //for(int i=1;i<=MAXN;i++) dist[i]=INF;

    int u,v,c;
    for(int i=0;i<e;i++)
    {
        char uu, vv;
        int u,v;
        std::cin >> uu >> vv;
        u = (int)uu - 65;;
        v = (int)vv - 65;;
        E[u].push_back(Edge(v, Nodes[v].weight));
    }


    char ss;
    int s;
    std::cin >> ss;//起点。
    s = (int)ss - 65;
    cout<<"起点:"<<ss<<endl;
   
    dist[s]=0;
    dfs(s);
    int ans=-INF;
    for(int i=1;i<=n;i++)
    {
        ans=max(dist[i], ans);
    }
    cout<<"输出: "<<ans + Nodes[s].weight<<endl;

    return 0;
}