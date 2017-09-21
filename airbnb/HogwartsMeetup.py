# You are at hogwarts alumni meetup with 9 other wizards.	Each wizard has a level
# 0 to 9, and knowns a few oher people at the meetup.
# You have a lowly level 0 and to advance you are looking to meet the level 9
# wizard.
# There's a catch:
# whenever some makes a introduction you must use some magic equal to square of the
# difference between the introducer and person being introduced
# (e.g. if a level 6 introduces you to a level 8 you must use 4 magic points)
# The function parameter wizards, is a string array with integers of wizardi
# separated by space. Each value indicates the other people each wizard knows.
# Note that relationships are one directional(e.g. 2 can introduce you to 3 but
# not vice versa) Your goal is to meet the level 9 wizard using fewest possible
# magic points. Compute the path and return it as an array starting with your 0th
# position. If it's not possible to meet Wizard level 9. return an array [0]

from collections import defaultdict
from heapq import *


def dijkstra_raw(edges, from_node, to_node):
    g = defaultdict(list)
    for l, r, c in edges:
        g[l].append((c, r))
    q, seen = [(0, from_node, ())], set()
    while q:
        (cost, v1, path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = (v1, path)
            if v1 == to_node:
                return cost, path
            for c, v2 in g.get(v1, ()):
                if v2 not in seen:
                    heappush(q, (cost + c, v2, path))
    return float("inf"), []


def dijkstra(edges, from_node, to_node):
    len_shortest_path = -1
    ret_path = []
    length, path_queue = dijkstra_raw(edges, from_node, to_node)
    if len(path_queue) > 0:
    	# 1. Get the length firstly
        len_shortest_path = length  
        # 2. Decompose the path_queue, to get the passing nodes in the shortest
        # path.
        left = path_queue[0]
        ret_path.append(left)  # 2.1 Record the destination node firstly;
        right = path_queue[1]
        while len(right) > 0:
            left = right[0]
            # 2.2 Record other nodes, till the source-node.
            ret_path.append(left)
            right = right[1]
        # 3. Reverse the list finally, to make it be normal sequence.
        ret_path.reverse()
    return len_shortest_path, ret_path


def meet(wizard):
    edges = []
    for i in range(len(wizard)):
        #line = map(int, wizard[i].split())
        for j in wizard[i]:
            edges.append((i, j, (i - j)**2))
    length, Shortest_path = dijkstra(edges, 0, 9)
    print "=== Dijkstra ==="
    print "Let's find the shortest-path from 0 to 9:"
    print 'length = ', length
    print 'The shortest path is ', Shortest_path

    if length == -1:
        return [0]
    return Shortest_path

# ==================== Given a list of nodes in the topology shown in Fig. 1.
list_nodes_id = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# ==================== Given constants matrix of topology.
M = 99999  # This represents a large distance. It means that there is no link.
# M_topo is the 2-dimensional adjacent matrix used to represent a topology.
M_topo = [
    [1, 2, 3],
    [8, 6, 4],
    [7, 8, 3],
    [8, 1],
    [6],
    [8, 7],
    [9, 4],
    [4, 6],
    [1],
    [1, 4],
]

meet(M_topo)
