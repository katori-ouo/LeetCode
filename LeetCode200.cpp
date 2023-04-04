#include <iostream>
#include <vector>
#include <unordered_map>
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
    int numIslands(vector<vector<char>> &grid)
    {
        UnionFind uf;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    uf.add(i * n + j + 1);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0'; // FIXME:为什么要设为'0'?
                    if (i >= 1 && grid[i - 1][j] == '1')
                        uf.merge(i * n + j + 1, (i - 1) * n + j * 1);
                    if (j <= n - 2 && grid[i][j + 1] == '1')
                        uf.merge(i * n + j + 1, i * n + j + 2);
                    if (i <= m - 2 && grid[i + 1][j] == '1')
                        uf.merge(i * n + j + 1, (i + 1) * n + j + 1);
                    if (j >= 1 && grid[i][j - 1] == '1')
                        uf.merge(i * n + j + 1, i * n + j);
                }
            }
        }
        return uf.getCnt();
    }
};