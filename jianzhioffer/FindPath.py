# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        if not root:
            return []
        result = []
        def find_path(root, path, currentsum):
            currentsum += root.val
            path.append(root)
            isleaf = root.left == None and root.right == None
            if currentsum == expectNumber and isleaf:
                onepath = []
                for node in path:
                    onepath.append(node.val)
                result.append(onepath)
            if currentsum < expectNumber:
                if root.left:
                    find_path(root.left, path, currentsum)
                if root.right:
                    find_path(root.right, path, currentsum)
            path.pop()
        find_path(root, [], 0)
        return result