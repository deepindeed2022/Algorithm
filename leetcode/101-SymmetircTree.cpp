#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r):val(x), left(l), right(r){}
    void free_tree(TreeNode* p, TreeNode* parent)
    {
        if(!p) return;
        free_tree(p->left, p);
        free_tree(p->right, p);

        if(parent == NULL)
        {
            delete p;
        }
        else if(parent->left == p)
        {
            parent->left = NULL;
            delete p;
        }
        else if (parent->right == p)
        {
            parent->right = NULL;
            delete p;
        }
    }
    ~TreeNode()
    {
        if(left != NULL)
            delete left;
        if(right != NULL)
            delete right;

    }
};

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        TreeNode* left, *right;
        if(!root) return true;
        std::queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty())
        {
            left = q1.front();
            q1.pop();

            right = q2.front();
            q2.pop();

            if(left == NULL && right == NULL)
                continue;
            if(NULL == left || NULL == right)
                return false;
            if(left->val != right->val)
                return false;

            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};
TreeNode* init_tree()
{
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(2);
    TreeNode* root = new TreeNode(1, left, right);
    TreeNode* ll = new TreeNode(3);
    TreeNode* rr = new TreeNode(3);
    left->left = ll;
    right->right = rr;
    return root;
}
void free_tree(TreeNode* root)
{

}
void test_isSymmetic()
{
    Solution solve;
    TreeNode* root = init_tree();
    std::cout <<std::boolalpha <<solve.isSymmetric(root) << std::endl;
}
int main(int argc, char const *argv[])
{
    test_isSymmetic();
    return 0;
}