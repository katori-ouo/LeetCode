#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *ptr) : val(x), next(ptr) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *p1, TreeNode *p2) : val(x), left(p1), right(p2) {}
};

int main()
{
    /*
    ! cin, 需要头文件<iostream>
    ! 单独/批量读入，以空格、tab、换行符为分隔符
    ! 从第一个非空格字符开始，遇到分隔符结束
    ! cout, 需要头文件<iostream>
    ! 输出endl时, 会输出一个换行符, 类似'\n'
    // & 1.读取单独输入
    int num;
    cin >> num;
    cout << num << '\n';
    // & 2.读取多个输入
    vector<int> nums(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout << nums[i] << " ";
    }
    cout << '\n';
    */

    /*
    ! getline(), 需要头文件<string>
    ! 读取一行, 包括空格, 遇到换行符结束
    // & 1.读取一行
    string s;
    getline(cin, s);
    cout << s << '\n';
    */

    /*
    ! getchar()
    ! 读取一个字符, 经常用于判断是否换行
    // & 1.读取一个字符
    char c;
    c = getchar();
    cout << c << '\n';
    */

    /*
    ! 读取固定长度一维数组
    3
    1 2 3
    or
    3 1 2 3
    int len;
    cin >> len;
    vector<int> nums(len);
    for (int i = 0; i < len; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << " ";
    }
    cout << '\n';
    */

    /*
    ! 读取不固定长度一维数组
    1 2 3 4
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
        if (getchar() == '\n')
            break;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << '\n';
    */

    /*
    ! 读取二维数组
    2 3
    1 2 3
    4 5 6
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << matrix[i][n - 1] << '\n';
    }
    */

    /*
    ! 读取二维数组
    2 3
    1,2,3
    4,5,6
    int m; // 接收行数
    int n; // 接收列数

    cin >> m >> n;
    cin.ignore();
    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i++)
    {
        // 读入字符串
        string s;
        getline(cin, s);

        // 将读入的字符串按照逗号分隔为vector<int>
        vector<int> vec;
        int p = 0;
        for (int q = 0; q < s.size(); q++)
        {
            p = q;
            while (s[p] != ',' && p < s.size())
            {
                p++;
            }
            string tmp = s.substr(q, p - q);
            vec.push_back(stoi(tmp));
            q = p;
        }

        // 写入matrix
        matrix[i] = vec;
        vec.clear();
    }

    // 验证是否读入成功
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    */

    /*
    ! 读取单个字符串
    string s;
    cin >> s;
    cout << s << endl;
    */

    /*
    ! 读取给定数目字符串
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << words[i] << endl;
    }
    */

    /*
    ! 读取不给定数目字符串
    vector<string> words;
    string s;
    while (cin >> s)
    {
        words.push_back(s);
        if (getchar() == '\n')
            break;
    }
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << " ";
    }
    cout << endl;
    */

    /*
    ! 字符串转数组
    string s;
    vector<int> nums;
    getline(cin, s);
    int p = 0;
    for (int q = 0; q < s.size(); q++)
    {
        p = q;
        while (s[p] != ',' && p < s.size())
        {
            p++;
        }
        string temp = s.substr(q, p - q);
        nums.push_back(stoi(temp));
        q = p;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    */

    /*
    ! 根据输入创建链表
    ListNode* dummyHead = new ListNode(-1);
    ListNode* cur = dummyHead;
    ListNode* node = nullptr;
    int num;
    while (cin >> num)
    {
        node = new ListNode(num);
        cur->next = node;
        cur = cur->next;
        if (getchar() == '\n')
            break;
    }
    cur = dummyHead->next;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    */

    /*
    ! 根据输入创建二叉树
    1 2 3 4 -1 -1 5
    1,2,3,4,null,null,5
    */
    vector<int> nums;
    // int num;
    // while (cin >> num)
    // {
    //     nums.push_back(num);
    //     if (getchar() == '\n')
    //         break;
    // }
    string s;
    getline(cin, s);
    int p = 0;
    for (int q = 0; q < s.size(); q++)
    {
        p = q;
        while (s[p] != ',' && p < s.size())
        {
            p++;
        }
        string temp = s.substr(q, p - q);
        if (temp == "null")
            nums.push_back(-1);
        else
            nums.push_back(stoi(temp));
        q = p;
    }
    vector<TreeNode *> vecTree(nums.size(), nullptr);
    TreeNode *root = nullptr;
    root = new TreeNode(nums[0]);
    vecTree[0] = root;
    for (int i = 1; i < nums.size(); i++)
    {
        TreeNode *node = nullptr;
        if (nums[i] != -1)
            node = new TreeNode(nums[i]);
        vecTree[i] = node;
    }
    for (int i = 0; i * 2 + 1 < nums.size(); i++)
    {
        if (vecTree[i] != nullptr)
        {
            vecTree[i]->left = vecTree[2 * i + 1];
            if (i * 2 + 2 < nums.size())
                vecTree[i]->right = vecTree[2 * i + 2];
        }
    }
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        int len = que.size();
        for (int i = 0; i < len; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            if (node)
            {
                cout << node->val << " ";
                que.push(node->left);
                que.push(node->right);
            }
            else
                cout << -1 << " ";
        }
        cout << endl;
    }
}