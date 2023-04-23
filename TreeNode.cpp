// ! /*前序递归遍历*/
// class Solution
// {
// public:
//     void traversal(TreeNode *cur, vector<int> &vec)
//     {
//         if (cur == NULL)
//             return;
//         vec.push_back(cur->val);    // 中
//         traversal(cur->left, vec);  // 左
//         traversal(cur->right, vec); // 右
//     }
//     vector<int> preorderTraversal(TreeNode *root)
//     {
//         vector<int> result;
//         traversal(root, result);
//         return result;
//     }
// };
// ! /*中序递归遍历*/
// void traversal(TreeNode *cur, vector<int> &vec)
// {
//     if (cur == NULL)
//         return;
//     traversal(cur->left, vec);  // 左
//     vec.push_back(cur->val);    // 中
//     traversal(cur->right, vec); // 右
// }
// ! /*后序递归遍历*/
// void traversal(TreeNode *cur, vector<int> &vec)
// {
//     if (cur == NULL)
//         return;
//     traversal(cur->left, vec);  // 左
//     traversal(cur->right, vec); // 右
//     vec.push_back(cur->val);    // 中
// }
// ! /*前序迭代遍历*/
// class Solution
// {
// public:
//     vector<int> preorderTraversal(TreeNode *root)
//     {
//         stack<TreeNode *> st;
//         vector<int> result;
//         if (root == NULL)
//             return result;
//         st.push(root);
//         while (!st.empty())
//         {
//             TreeNode *node = st.top(); // 中
//             st.pop();
//             result.push_back(node->val);
//             if (node->right)
//                 st.push(node->right); // 右（空节点不入栈）
//             if (node->left)
//                 st.push(node->left); // 左（空节点不入栈）
//         }
//         return result;
//     }
// };
// ! /*中序迭代遍历*/
// class Solution
// {
// public:
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> result;
//         stack<TreeNode *> st;
//         TreeNode *cur = root;
//         while (cur != NULL || !st.empty())
//         {
//             if (cur != NULL)
//             {                    // 指针来访问节点，访问到最底层
//                 st.push(cur);    // 将访问的节点放进栈
//                 cur = cur->left; // 左
//             }
//             else
//             {
//                 cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
//                 st.pop();
//                 result.push_back(cur->val); // 中
//                 cur = cur->right;           // 右
//             }
//         }
//         return result;
//     }
// };
// ! /*后序迭代遍历*/
// class Solution
// {
// public:
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         stack<TreeNode *> st;
//         vector<int> result;
//         if (root == NULL)
//             return result;
//         st.push(root);
//         while (!st.empty())
//         {
//             TreeNode *node = st.top();
//             st.pop();
//             result.push_back(node->val);
//             if (node->left)
//                 st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
//             if (node->right)
//                 st.push(node->right); // 空节点不入栈
//         }
//         reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
//         return result;
//     }
// };

// ! /*层序迭代遍历*/
// class Solution
// {
// public:
//     vector<vector<int>> levelOrder(TreeNode *root)
//     {
//         queue<TreeNode *> que;
//         if (root != NULL)
//             que.push(root);
//         vector<vector<int>> result;
//         while (!que.empty())
//         {
//             int size = que.size();
//             vector<int> vec;
//             // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
//             for (int i = 0; i < size; i++)
//             {
//                 TreeNode *node = que.front();
//                 que.pop();
//                 vec.push_back(node->val);
//                 if (node->left)
//                     que.push(node->left);
//                 if (node->right)
//                     que.push(node->right);
//             }
//             result.push_back(vec);
//         }
//         return result;
//     }
// };
#include <iomanip>
cout << fixed << setprecision(2) << i;
// ! /*平衡二叉树*/
class Solution
{
public:
    // 返回以该节点为根节点的二叉树的高度，如果不是平衡二叉树了则返回-1
    int getHeight(TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1)
            return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) == -1 ? false : true;
    }
};