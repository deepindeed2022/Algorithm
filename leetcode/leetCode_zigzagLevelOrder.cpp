#include <vector>
using std::vector;
#include <iostream>
using std::cout;

class TreeNode
{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
};

class Solution {
public:
    void travel(TreeNode* cur, vector<vector<int> > &res, int level) {
        if (cur == NULL)    return;

        if (res.size() <= level) {
            vector<int> newLevel;
            res.push_back(newLevel);
        }

        if (level % 2 == 0)
            res[level].push_back(cur->val);
        else
            res[level].insert(res[level].begin(), cur->val);

        travel(cur->left, res, level+1);
        travel(cur->right, res, level+1);
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        travel(root, res, 0);
        return res;
    }
};