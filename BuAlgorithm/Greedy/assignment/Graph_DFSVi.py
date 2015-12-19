
class count_tree_edges_dfs_visitor(bgl.Graph.DFSVisitor):
  def __init__(self, name_map):
    bgl.Graph.DFSVisitor.__init__(self)
    self.name_map = name_map

  def tree_edge(self, e, g):
    (u, v) = (g.source(e), g.target(e))
    print "Tree edge ",
    print self.name_map[u],
    print " -> ",
    print self.name_map[v]