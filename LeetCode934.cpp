#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class UnionFind
{
private:
    unordered_map<int, int> father;
    int cnt = 0;

public:
    int find(int x)
    {
        int root = x;
        while (father[root] != -1)
        {
            root = father[root];
        }
        while (x != root)
        {
            int originalRoot = father[x];
            father[x] = root;
            x = originalRoot;
        }
        return root;
    }

    void add(int x)
    {
        if (!father.count(x))
        {
            father[x] = -1;
            cnt++;
        }
    }

    void merge(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            father[rootX] = rootY;
            cnt--;
        }
    }

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }

    int getCnt()
    {
        return cnt;
    }
};

class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf;
        int root1 = -2;
        int step = 0;
        queue<pair<int, int>> que;
        // unordered_map<pair<int, int>, bool> canUse;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    uf.add(i * n + j + 1);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = -1;
                    if (i >= 1 && grid[i - 1][j] == 1)
                        uf.merge((i - 1) * n + j + 1, i * n + j + 1);
                    if (j <= n - 2 && grid[i][j + 1] == 1)
                        uf.merge(i * n + j + 2, i * n + j + 1);
                    if (i <= m - 2 && grid[i + 1][j] == 1)
                        uf.merge((i + 1) * n + j + 1, i * n + j + 1);
                    if (j >= 1 && grid[i][j - 1] == 1)
                        uf.merge(i * n + j, i * n + j + 1);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == -1)
                {
                    int root = uf.find(i * n + j + 1);
                    if (root1 == -2)
                    {
                        root1 = root;
                        grid[i][j] = 1;
                        que.push({i, j});
                        // canUse[{i, j}] = false;
                    }
                    else
                    {
                        if (root == root1)
                        {
                            grid[i][j] = 1;
                            que.push({i, j});
                            // canUse[{i, j}] = false;
                        }
                    }
                }
            }
        }
        while (!que.empty())
        {
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                int x = que.front().first, y = que.front().second;
                que.pop();
                // 上
                if (x >= 1)
                {
                    if (grid[x - 1][y] == -1)
                        return step;
                    if (grid[x - 1][y] == 0)
                    {
                        grid[x - 1][y] = 1;
                        que.push({x - 1, y});
                    }
                }
                // 右
                if (y <= n - 2)
                {
                    if (grid[x][y + 1] == -1)
                        return step;
                    if (grid[x][y + 1] == 0)
                    {
                        grid[x][y + 1] = 1;
                        que.push({x, y + 1});
                    }
                }
                // 下
                if (x <= m - 2)
                {
                    if (grid[x + 1][y] == -1)
                        return step;
                    if (grid[x + 1][y] == 0)
                    {
                        grid[x + 1][y] = 1;
                        que.push({x + 1, y});
                    }
                }
                // 左
                if (y >= 1)
                {
                    if (grid[x][y - 1] == -1)
                        return step;
                    if (grid[x][y - 1] == 0)
                    {
                        grid[x][y - 1] = 1;
                        que.push({x, y - 1});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    Solution solve;
    int res = solve.shortestBridge(grid);
    return 0;
}