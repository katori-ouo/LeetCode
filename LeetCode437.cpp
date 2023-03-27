#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 二叉树结点的定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution
{
public:
    int cnt;
    unordered_map<long long, int> mp;
    void dfs(TreeNode *node, long long pre, int targetSum)
    {
        if (node == nullptr)
            return;
        pre += node->val;
        if (mp.count(pre - targetSum))
            cnt += mp[pre - targetSum];
        mp[pre]++;
        dfs(node->left, pre, targetSum);
        dfs(node->right, pre, targetSum);
        mp[pre]--;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        cnt = 0;
        mp[0] = 1;
        dfs(root, 0, targetSum);
        return cnt;
    }
};
