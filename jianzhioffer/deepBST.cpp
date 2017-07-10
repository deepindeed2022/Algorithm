#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution
{
 public:
   // int TreeDepth(TreeNode* pRoot)
   // {
   // 	if(pRoot==NULL) return 0;
   //     return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
   // }
   int TreeDepth(TreeNode *pRoot)
   {
      if (pRoot == NULL)
         return 0;
      int depth     = 0;

      queue<TreeNode *> que;
      que.push(pRoot);
      while (!que.empty())
      {
         int size = que.size();
         depth++;
         for (int i = 0; i < size; i++)
         {
         	TreeNode *node = que.front();
            que.pop();
            if (node->left)
               que.push(node->left);
            if (node->right)
               que.push(node->right);
         }

      }
      return depth;
   }
};