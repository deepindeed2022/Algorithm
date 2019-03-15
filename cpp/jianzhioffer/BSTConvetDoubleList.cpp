/***************************************************************************
 *
 * 将一颗二叉树转化为双向链表的操作
 * 思路：
 * 采用中序遍历的想法的，对二叉树进行中序遍历，遍历过程就是最终的结果过程，然后将
 * 前后进行指针的重新设置即可。
 * 本题目主要考察递归和指针的操作
 *
 **************************************************************************/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return pRootOfTree;
        pRootOfTree = ConvertNode(pRootOfTree);
        // 获取头节点的地址，最小的值对应的指针地址
        while(pRootOfTree->left) pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }
    // 进行中序遍历
    TreeNode* ConvertNode(TreeNode* root)
    {
        if(root == NULL) return root;
		// 中序遍历左子树
        if(root->left)
        {
            TreeNode *left = ConvertNode(root->left);
            while(left->right) left = left->right;
            left->right = root;
            root->left = left;
        }
        // 中序遍历右子树
        if(root->right)
        {
            TreeNode *right = ConvertNode(root->right);
            while(right->left) right = right->left;
            right->left = root;
            root->right = right;
        }
        return root;
    }
};