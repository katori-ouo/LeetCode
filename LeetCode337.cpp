#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> robTree(TreeNode *root)
    {
        vector<int> val(2, 0);
        // val[0]:抢该结点, val[1]:不抢该结点
        if (root == nullptr)
            return val;
        vector<int> leftVal = robTree(root->left);
        vector<int> rightVal = robTree(root->right);
        val[0] = root->val + leftVal[1] + rightVal[1];
        val[1] = max(leftVal[0], leftVal[1]) + max(rightVal[0], rightVal[1]);
        return val;
    }

    int rob(TreeNode *root)
    {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};
