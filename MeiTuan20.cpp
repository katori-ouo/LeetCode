#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int n, k, root;
    int maxVal = INT32_MIN;
    int idx = -1;
    vector<vector<int>> connections;
    vector<int> weights;
    vector<bool> isUsed;
    vector<int> nodeNum;
    vector<int> valMax;
    vector<int> valMin;
    Solution(int N, int K)
    {
        n = N;
        k = K;
        connections.resize(n + 1, vector<int>());
        weights.resize(n + 1, 0);
        isUsed.resize(n + 1, false);
        nodeNum.resize(n + 1, 0);
        valMax.resize(n + 1, 0);
        valMin.resize(n + 1, 0);
    }

    void getInput()
    {
        int x, y;
        for (int i = 1; i <= n; i++)
        {
            cin >> weights[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> y;
            connections[x].emplace_back(y);
            connections[y].emplace_back(x);
        }
        cin >> root;
    }

    void dfs(int x)
    {
        nodeNum[x] = 1;
        valMax[x] = weights[x];
        valMin[x] = weights[x];
        isUsed[x] = true;
        for (int node : connections[x])
        {
            if (!isUsed[node])
            {
                dfs(node);
                nodeNum[x] += nodeNum[node];
                valMax[x] = max(valMax[x], valMax[node]);
                valMin[x] = min(valMin[x], valMin[node]);
            }
        }
        int temp = valMax[x] - valMin[x];
        if (nodeNum[x] <= k)
        {
            if (temp > maxVal)
            {
                maxVal = temp;
                idx = x;
            }
            if (temp == maxVal)
            {
                idx = min(idx, x);
            }
        }
    }

    void getRes()
    {
        dfs(root);
        cout << idx << '\n';
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    Solution solve(n, k);
    solve.getInput();
    solve.getRes();
}