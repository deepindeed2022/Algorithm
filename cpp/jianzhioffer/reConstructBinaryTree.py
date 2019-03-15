# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        sz = len(pre)
        if sz == 0: return None
        return self.__buildBTree(pre, tin)

    def __buildBTree(self, pre, tin):
        if len(pre) == 0:
            return None
        if len(pre) == 1:
            return TreeNode(pre[0])
        i = 0
        head = TreeNode(pre[0])
        while i < len(tin) and tin[i] != pre[0]:
            i += 1
        
        head.left = self.__buildBTree(pre[1:i+1], tin[0:i])
        head.right = self.__buildBTree(pre[i+1:],tin[i+1:])
        return head



# 先序遍历一棵树
def pre_print_tree(treenode, result=[], verbose=False):
    if treenode:
        if verbose: print treenode.val,
        result.append(treenode.val)
        if treenode.left:
            pre_print_tree(treenode.left, result)
        if treenode.right:
            pre_print_tree(treenode.right, result)
# 后续遍历一棵树
def vin_print_tree(treenode, result=[], verbose=False):
    if treenode:
        if treenode.left:
            vin_print_tree(treenode.left, result)
        if verbose: print treenode.val,
        result.append(treenode.val)
        if treenode.right:
            vin_print_tree(treenode.right, result)    


def test_reconstruct():
    pre = [1,2,3,4,5,6,7]
    vin = [3,2,4,1,6,5,7]
    solve = Solution()       
    tree = solve.reConstructBinaryTree(pre, vin)
    result = []
    pre_print_tree(tree, result)
    assert all([x == y for (x, y) in zip(pre, result)])
    result = []
    vin_print_tree(tree, result)
    assert all([x == y for (x, y) in zip(vin, result)])
    #print result

if __name__ == '__main__':
    test_reconstruct()