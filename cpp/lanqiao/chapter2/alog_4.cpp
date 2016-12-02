/**********************************************************************************
 * 问题描述
    有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，
    那么在树上和它相邻的点都不能被选择。求选出的点的权值和最大是多少？

 * 输入格式
    第一行包含一个整数 n 。
    接下来的一行包含 n 个正整数，第 i 个正整数代表点 i 的权值。
    接下来一共 n-1 行，每行描述树上的一条边。

 * 输出格式
    输出一个整数，代表选出的点的权值和的最大值。
************************************************************************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define M 100100
typedef struct Node{
    int vex;
    Node* next;
}* ChildPtr, Child;

ChildPtr head[M];
int f[M][2], pow[M],visit[M];

void add_sym_connect(int u, int v)
{
    ChildPtr p, q;
    p = (ChildPtr) malloc(sizeof(Child));
    p->vex = v;
    p->next = head[u];
    head[u] = p;

    q = (ChildPtr) malloc(sizeof(Child));
    q->vex = u;
    q->next = head[v];
    head[v] = q;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}