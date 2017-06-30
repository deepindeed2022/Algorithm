/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
    	queue<TreeNode*> q;
    	vector<int> result;
    	if(root == NULL) return result;
    	q.push(root);
    	while(!q.empty())
    	{
    		TreeNode* head = q.front();
    		q.pop();
    		if(head->left) q.push(head->left);
    		if(head->right) q.push(head->right);
    		result.push_back(head->val);
    	}
    	return result;
    }
};