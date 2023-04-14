#include <iostream>
#include <vector>
using namespace std;
/* 贪心算法 监控二叉树 */
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
    int res;
    int traversal(TreeNode *cur)
    {
        if (cur == nullptr)
            return 2;
        int left = traversal(cur->left);
        int right = traversal(cur->right);

        if (left == 2 && right == 2)
            return 0;
        if (left == 0 || right == 0)
        {
            res++;
            return 1;
        }
        if (left == 1 || right == 1)
        {
            return 2;
        }
        return -1;
    }
    int minCameraCover(TreeNode *root)
    {
        res = 0;
        if (traversal(root) == 0)
            res++;
        return res;
    }
};
