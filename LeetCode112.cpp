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
    bool traversal(TreeNode *node, int num)
    {
        num -= node->val;
        if (!node->left && !node->right)
        {
            if (num == 0)
                return true;
            else
                return false;
        }
        bool leftPath = false, rightPath = false;
        if (node->left)
            leftPath = traversal(node->left, num);
        if (node->right)
            rightPath = traversal(node->right, num);
        bool res = leftPath || rightPath;
        return res;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        bool res = traversal(root, targetSum);
        return res;
    }
};
