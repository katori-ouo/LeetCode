#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int depth = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            depth++;
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *cur = que.front();
                que.pop();
                if (!cur->left && !cur->right)
                    return depth;
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
        }
        return depth;
    }
};