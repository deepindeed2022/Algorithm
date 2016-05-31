# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
      	def dfs(l, r):
      		if l == None:
      			return r == None
      		elif r == None:
      			return l == None
      		if l.left == None:
      			return dfs(l.right, r.left) if l.right == None   else False
      		if l.right == None:
      			return dfs(l.left, r.right) if l.left == None else False
      		
      		if l.val == r.val:
      			return dfs(l.left,r.right) and dfs(l.right, r.left)
      		else:
      			return False
      	if root == None:
      		return True
      	if root.left == None or root.right == None:
      		if root.left == None and root.right == None: return True
      		else: return False

      	if root.left.val == root.right.val:
      		return dfs(root.left,root.right)
      	else:
      		return False
