##  问题
输入一颗树，判断树是不是对称的树



## 问题思路

可以使用递归的方法进行,关键是终止条件要好好制定清楚。跟树这种数据结构相关的考题，十有八九需要使用递归的。


```cpp
bool isSymmetric(TreeNode* root)
{
	return root ? isSymmetric(root->right, root->left) : true;
}
bool isSymmetric(TreeNode* left, TreeNode* right)
{
	if(!left && !right) return true;
	if(!left|| !right) return false;
	return left->val == right->val && isSymmetric(left->left, right->right)
									&& isSymmetric(left->right, right->left);
}
```

或者使用迭代的方式，使用两个**队列**进行存储中间访问节点。通过对称性地比较节点的是否相等判断某个树是不是对称的。

```cpp
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
```