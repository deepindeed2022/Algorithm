#include <vector>
#include <stack>
#include <iostream>
#include "utils.h"
using namespace std;
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> result;
	const TreeNode*p = root;
	statck<const TreeNode*> s;
	while(!s.empty() || p!= NULL)
	{
		if(p != NULL)
		{
			s.push(p);
			p = p->left; // traverse the left child
		}
		else
		{
			p = s.top();
			s.pop();
			result.push_back(p->val);//traverse the node
			p = p->right;
		}
	}
	return result;
}

vector<int> inorderTraversal_morris(TreeNode* root)
{
	vector<int> result;
	TreeNode* prev = NULL;
	TreeNode* cur = root;
	while(cur != NULL)
	{
		if(cur->left == NULL)
		{
			result.push_back(cur->val);
			prev = cur;
			cur = cur->right;
		}
		else
		{
			TreeNode* node = cur->left;
			while(node->right != NULL && node->right != cur)
				node = node->right;
			if(node->right == NULL)
			{
				node->right = cur;
				cur = cur->left;
			}
			else
			{
				result.push_back(cur->val);
				node->right = NULL;
				prev = cur;
				cur = cur->right;
			}
		}
	}
}
// http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
// 本文主要解决一个问题，如何实现二叉树的前中后序遍历，有两个要求：
// 1. O(1)空间复杂度，即只能使用常数空间；
// 2. 二叉树的形状不能被破坏（中间过程允许改变其形状）。
// 通常，实现二叉树的前序（preorder）、中序（inorder）、后序（postorder）遍历有两个常用的方法：
// 一是递归(recursive)，二是使用栈实现的迭代版本(stack+iterative)。
// 这两种方法都是O(n)的空间复杂度（递归本身占用stack空间或者用户自定义的stack），
// 以不满足要求。（用这两种方法实现的中序遍历实现可以参考这里。）
// Morris Traversal方法可以做到这两点，与前两种方法的不同在于该方法只需要O(1)空间，
// 而且同样可以在O(n)时间内完成。
// 要使用O(1)空间进行遍历，最大的难点在于，遍历到子节点的时候怎样重新返回到父节点
// （假设节点中没有指向父节点的p指针），由于不能用栈作为辅助空间。为了解决这个问题，
// Morris方法用到了线索二叉树（threaded binary tree）的概念。在Morris方法中
// 不需要为每个节点额外分配指针指向其前驱（predecessor）和后继节点（successor），
// 只需要利用叶子节点中的左右空指针指向某种顺序遍历下的前驱节点或后继节点就可以了。
// Morris只提供了中序遍历的方法，在中序遍历的基础上稍加修改可以实现前序，而后续
// 就要再费点心思了。所以先从中序开始介绍。

// Morris Algorithm:
// 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
// 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
//    a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
//    b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。
//       当前节点更新为当前节点的右孩子。
// 3. 重复以上1、2直到当前节点为空。