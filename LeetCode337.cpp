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
    vector<int> robTree(TreeNode *cur)
    {
        // dp[0]:不抢该结点时的最高金额
        // dp[1]:抢该结点时的最高金额
        vector<int> dp(2, 0);
        if (cur == nullptr)
            return dp;
        vector<int> leftVal = robTree(cur->left);
        vector<int> rightVal = robTree(cur->right);
        dp[0] = max(leftVal[0], leftVal[1]) + max(rightVal[0], rightVal[1]);
        dp[1] = cur->val + leftVal[0] + rightVal[0];
        return dp;
    }

    int rob(TreeNode *root)
    {
        vector<int> dp = robTree(root);
        return max(dp[0], dp[1]);
    }
};
