/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
using namespace std;
  
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	if(pre.empty()) return NULL;
    	return subTree(pre, vin, 0, 0, pre.size());
    }
private:
	TreeNode* subTree(vector<int> pre, vector<int> vin, int prevstart, int vinstart, int size)
	{
		if(size == 0) return NULL;
		TreeNode* head = new TreeNode(pre[prevstart]);
		int i = vinstart;
		while(i < vinstart + size && vin[i] != pre[prevstart]) i++;
		int lsz = i - vinstart;
		int rsz = size - i;
		head->left = subTree(pre, vin, prevstart + 1, vinstart, lsz);
		head->right = subTree(pre,vin, i+1, lsz + prevstart + 1, rsz);
		return head;
	}
};