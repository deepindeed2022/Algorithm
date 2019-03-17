#!/usr/bin/python 
# -*- coding: utf-8 -*- 
"""
【第三题】路径规划
假设现在有一个有向无环图，每个节点上都带有正数权重。我们希望找到一条最优路径，使得这个路径上经过的节点的权重之和最大。
输入：n个节点，m个路径，起点
输出：最优路径的权重值之和
举例：
3个节点：
A 1
B 2
C 2
3条路径：
A->B
B->C
A->C
起点：
A
输出：5  （最优路径是 A->B->C ， 权重之和是 1+2+2=5）
附加问题：我们要求的输入是有向无环图，但是没人知道实际使用的时候会有什么数据输入进来，如何避免输入了带环路的图导致的死循环呢？
"""

import sys

class Node:
	def __init__(self, _id, _weight=0):
		self.id = _id;
		self.weight = _weight

class Edge:
	def __init__(self, _v, _cost=0):
		self.v = _v;
		self.cost = _cost


def dfs(Edges, start, dist, visited):
	# 0代表未访问，白色，1代表访问了，但是它的邻居还没被访问完，灰色；2代表访问了，并且它的邻居全部都被访问了，黑色。
	visited[start] = True; 
	try:
		e = Edges[start]
	except KeyError:
		print "{} is a tail node".format(start)
		return

	for v in e:
		vv = v.v
		cost = v.cost
		if visited[vv]: continue
		dist[vv] = dist[start] + cost

		dfs(Edges, vv, dist, visited)


def max_node_weight_path(nodes, edges, start):
	visited = dict()
	dist = dict()
	for i in nodes:
		visited[i] = False
	dist[start] = 0
	dfs(edges, start, dist, visited)
	res = max(dist.values()) + nodes[start].weight
	print "Max value is:{}".format(res)
	

def main():
	Nodes = dict()
	Edges = dict([])
	paths = dict()
	print "Input n, m"
	line = sys.stdin.readline().strip()
	n, m = map(int, line.split())
	# read nodes
	print "Input nodes: [nodename  value]"
	for _ in xrange(n):
		node, val = sys.stdin.readline().strip().split()
		Nodes[node] = Node(node, int(val))

	for k, v in Nodes.iteritems():
		print k, v.weight
	print Nodes.keys()

	# read edge
	print "Input edges: [headnode  tailnode]"
	for _ in xrange(m):
		u, v = sys.stdin.readline().split()
		if u in Edges:
			Edges[u].append(Edge(v, Nodes[v].weight))
		else:
			Edges[u] = [Edge(v, Nodes[v].weight)]

	start = sys.stdin.readline().strip()

	max_node_weight_path(Nodes, Edges, start)

if __name__ == '__main__':
	sys.stdin = open('input.dat')
	sys.stdout = open("out.log", "w+")
	main()
