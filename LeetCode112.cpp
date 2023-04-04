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
    bool backtracking(TreeNode *cur, int sum)
    {
        sum -= cur->val;
        if (!cur->left && !cur->right)
        {
            if (sum == 0)
                return true;
            else
                return false;
        }
        bool leftRes = false, rightRes = false;
        if (cur->left)
            leftRes = backtracking(cur->left, sum);
        if (cur->right)
            rightRes = backtracking(cur->right, sum);
        return (leftRes || rightRes);
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        return backtracking(root, targetSum);
    }
};
