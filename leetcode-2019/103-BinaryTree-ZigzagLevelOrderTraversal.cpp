#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
} TreeNode;

/*************************************************************************
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
[0]
[2, 1]
[3, 4, 5, 6]
[14, 13, 12, 11, 10, 9, 8, 7]

这个问题有两个解决方法
方法1. 使用一个队列存储访问过程中的按层进行reverse
方法2. 使用两个队列存储访问过程中的内容，偶数层的访问结果进行reverse
*************************************************************************/
class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        std::queue<TreeNode *> q; 
        q.push(root);
        bool rev = false;
        
        while (!q.empty()) {
            std::vector<int> v;
            int size = q.size();
            for (int i=0; i<size; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                v.push_back(tmp->val);

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            
            if (rev) reverse(v.begin(), v.end());
            res.push_back(v);
            rev = !rev;
        }
        
        return res;
    }


    std::vector<std::vector<int>> zigzagLevelOrder_2Queue(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;
        std::vector<TreeNode *> q1;
        std::vector<TreeNode *> q2;
        q1.push_back(root);
        
        while (!q1.empty() || !q2.empty()) {
            std::vector<int> v;
            if(!q1.empty()) {
                int size = q1.size();
                v.resize(size);
                for (int i = 0; i < size; i++) {
                    TreeNode *tmp = q1[i];
                    v[i] = (tmp->val);
                    if (tmp->left) q2.push_back(tmp->left);
                    if (tmp->right) q2.push_back(tmp->right);
                }
                q1.clear();
            }
            if(v.size() > 0) res.push_back(v);

            std::vector<int> v2;
            if(!q2.empty()) {
                int size = q2.size();
                v2.resize(size);
                for (int i = 0; i < size; i++) {
                    TreeNode *tmp = q2[i];
                    v2[size - i - 1] = (tmp->val);
                    if (tmp->left) q1.push_back(tmp->left);
                    if (tmp->right) q1.push_back(tmp->right);
                }
                q2.clear();
            }
            if(v2.size() > 0) {
                res.push_back(v2);
            }
        }
        
        return res;
    }
};


    
int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* root;
    int i;

    // Small test case
    root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 1;
    root->left = root->right = 0;
    std::vector<std::vector<int>> result = s.zigzagLevelOrder(root);
    fprintf(stderr, "Test 1: zigzagLevelOrder(root) =\n");
    fprintf(stderr, "[\n");
    for(auto& vv: result) {
        fprintf(stderr, "[");
        for(int i = 0; i < vv.size() - 1; i++) {
            fprintf(stderr, "%d, ", vv[i]);
        }
        fprintf(stderr, "%d]\n", vv[vv.size()-1]);
    }
    fprintf(stderr, "]\n");
    free(root);

    // Large test case
    root = (TreeNode*) malloc(101 * sizeof(TreeNode));
    for (i = 0; i < 50; i++) {
        root[i].val = i;
        root[i].left = &root[2*i + 1];
        root[i].right = &root[2*i + 2];
    }
    for (i = 50; i < 101; i++) {
        root[i].val = i;
    }
    result = s.zigzagLevelOrder(root);
    fprintf(stderr, "Test 2: zigzagLevelOrder(root) =\n");
    fprintf(stderr, "[\n");
    for(auto& vv: result) {
        fprintf(stderr, "[");
        for(int i = 0; i < vv.size() - 1; i++) {
            fprintf(stderr, "%d, ", vv[i]);
        }
        fprintf(stderr, "%d]\n", vv[vv.size()-1]);
    }
    fprintf(stderr, "]\n");

    result = s.zigzagLevelOrder_2Queue(root);
    fprintf(stderr, "Test 3: zigzagLevelOrder_2Queue(root) =\n");
    fprintf(stderr, "[\n");
    for(auto& vv: result) {
        fprintf(stderr, "[");
        for(int i = 0; i < vv.size() - 1; i++) {
            fprintf(stderr, "%d, ", vv[i]);
        }
        fprintf(stderr, "%d]\n", vv[vv.size()-1]);
    }
    fprintf(stderr, "]\n");
    free(root);
    return 0;
}