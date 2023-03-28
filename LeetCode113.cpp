#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(TreeNode *node, int n)
    {
        if (!node->left && !node->right)
        {
            if (n == 0)
                res.push_back(path);
            return;
        }
        if (node->left)
        {
            n -= node->left->val;
            path.push_back(node->left->val);
            backtracking(node->left, n);
            n += node->left->val;
            path.pop_back();
        }
        if (node->right)
        {
            n -= node->right->val;
            path.push_back(node->right->val);
            backtracking(node->right, n);
            n += node->right->val;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        res.clear();
        path.clear();
        if (root == nullptr)
            return res;
        path.push_back(root->val);
        backtracking(root, targetSum - root->val);
        return res;
    }
};
