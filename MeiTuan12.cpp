#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void buildTree(int x, vector<pair<int, int>> &connections, int n,
               vector<vector<int>> &nodes, vector<bool> &isRooted, vector<bool> &isUsed)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (!isUsed[i])
        {
            if (connections[i].first == x)
            {
                // if (!isRooted[connections[i].second])
                // {
                nodes[x].emplace_back(connections[i].second);
                isRooted[connections[i].second] = true;
                isUsed[i] = true;
                buildTree(connections[i].second, connections, n, nodes, isRooted, isUsed);
                // }
            }
            else if (connections[i].second == x)
            {
                // if (!isRooted[connections[i].first])
                // {
                nodes[x].emplace_back(connections[i].first);
                isRooted[connections[i].first] = true;
                isUsed[i] = true;
                buildTree(connections[i].first, connections, n, nodes, isRooted, isUsed);
                // }
            }
        }
    }
}

void cnt(int &x, vector<vector<int>> &nodes, vector<int> &colors,
         vector<unordered_map<int, int>> &nodeColor, vector<bool> &canUse)
{
    if (!canUse[x])
    {
        return;
    }
    else
    {
        nodeColor[x][colors[x]]++;
        for (int node : nodes[x])
        {
            cnt(node, nodes, colors, nodeColor, canUse);
            for (auto kv : nodeColor[node])
            {
                nodeColor[x][kv.first] += kv.second;
            }
        }
        canUse[x] = false;
    }
}

int maxColor(unordered_map<int, int> &nodeColor)
{
    int maxCnt = 0, res = 0;
    for (auto kv : nodeColor)
    {
        if (kv.second > maxCnt)
        {
            maxCnt = kv.second;
            res = kv.first;
        }
        else if (kv.second == maxCnt)
        {
            res = min(res, kv.first);
        }
    }
    return res;
}

int main()
{
    // 节点个数
    int n;
    cin >> n;
    // 记录每条边
    vector<pair<int, int>> connections;
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        connections.push_back({x, y});
    }
    // 把无向图变成有方向的树结构
    vector<vector<int>> nodes(n + 1, vector<int>());
    vector<bool> isRooted(n + 1, false); // 记录节点是否已经找到父节点
    vector<bool> isUsed(n - 1, false);   // 记录每条边是否已经被用过
    isRooted[0] = true;
    isRooted[1] = true;
    buildTree(1, connections, n, nodes, isRooted, isUsed);
    // 记录每个节点的颜色
    vector<int> colors(n + 1, 0);
    // int colorNum = INT32_MIN; // 最多的颜色种类
    for (int i = 0; i < n; i++)
    {
        cin >> colors[i + 1];
        // colorNum = max(colorNum, colors[i + 1]);
    }
    // 记录每个节点包含的每个颜色的个数
    vector<unordered_map<int, int>> nodeColor(n + 1, unordered_map<int, int>());
    // 记录每个节点是否已经被统计过
    vector<bool> canUse(n + 1, true);
    for (int i = 1; i <= n; i++)
    {
        cnt(i, nodes, colors, nodeColor, canUse);
    }
    // 每个节点下个数最多的苹果
    vector<int> ans(n + 1, -1);
    vector<int> out; // 最后输出的结果
    int q, node;     // 询问次数和询问的节点
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> node;
        if (ans[node] != -1)
            out.emplace_back(ans[node]);
        else
        {
            ans[node] = maxColor(nodeColor[node]);
            out.push_back(ans[node]);
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << out[i] << '\n';
    }
}