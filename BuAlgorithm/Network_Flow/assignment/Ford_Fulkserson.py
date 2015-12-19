import sys

def hasPath(rGraph, s, t, path, V):
	'''
	Find a path in reduce graph from source s to sink t 
	:param rGraph 
	:param s, t
	:param path  save path from s to t
	:return find path or not
	'''
	visited = [False for i in range(V)]
	queue = []
	queue.append(s)
	visited[s] = True
	while len(queue) > 0:
		top = queue.pop()
		for i in range(V):
			if not visited[i] and rGraph[top][i] > 0:
				queue.append(i)
				visited[i] = True
				path[i] = top
	return visited[t] == True

def maxFlow(graph, s, t):
	'''
	Find the max flow in graph from s to t
	:return max_flow
	:return pairs :this result only used in the girl-boys match
	'''
	V = len(graph)
	rGraph = graph
	maxflow = 0
	pairs = []
	path = [0 for i in range(V)]
	while hasPath(rGraph, s, t, path, V):
		min_flow = sys.maxint
		# find the bottle flow
		v = t
		while v != s:
			u = path[v]
			min_flow = min(min_flow, rGraph[u][v])
			v = path[v]
		# update edge weight
		v = t	
		while v != s:
			u = path[v]
			rGraph[u][v] -= min_flow
			rGraph[v][u] += min_flow
			v = path[v]	
		maxflow += min_flow
		pairs.append((path[path[t]], path[t]))
		path = [0 for i in range(V)]
	return maxflow, pairs

def Ford_fulkerson(graph, target):
	s = 0
	flow = maxFlow(graph, s, target)
	return flow