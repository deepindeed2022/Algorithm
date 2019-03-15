#include <vector>
using std::vector;
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    void traval(vector<TreeNode*>& level, vector<int>& subresult)
    {
        vector<TreeNode*> subLevel;
        vector<int> result;
        for(std::vector<TreeNode*>::iterator it = level.begin();
                it != level.end(); ++it)
        {
                result.push_back((*it)->val);
                if((*it)->left) subLevel.push_back((*it)->left);
                if((*it)->right) subLevel.push_back((*it)->right); 
        }
        level.clear();
        subresult.clear();
        subresult = result;
        level = subLevel;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> > result;
        vector<int> subresult;
        if(root == NULL) return result;
        vector<TreeNode*> level(1, root);
        while(level.size() != 0)
        {
            traval(level, subresult);
            result.push_back(subresult);
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}