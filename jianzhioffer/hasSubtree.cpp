/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
	bool isSubtree(TreeNode* root1, TreeNode* root2)
	{
		if(root2 == NULL) return true;
		if(root1 == NULL) return false;
		if(root1->val == root2->val)
			return isSubtree(root1->left, root2->left) && isSubtree(root1->right, root2->right);
		else
			return false;
	}
public:
    bool HasSubtree(TreeNode* root1, TreeNode* root2)
    {
		if(root1 == NULL || root2 == NULL) 
			return false;
		return isSubtree(root1, root2) || HasSubtree(root1->left, root2) || HasSubtree(root1->right, root2);
    }
};