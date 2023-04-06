#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
/*
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

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
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

    int getCnt()
    {
        return cnt;
    }
};

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        // unordered_map<int, vector<int>> mp;
        unordered_map<int, int> rec;
        int m = board.size();
        int n = board[0].size();
        UnionFind uf;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // mp[i * n + j + 1] = {m, n};
                if (board[i][j] == 'O')
                {
                    uf.add(i * n + j + 1);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'A';
                    if (i >= 1 && board[i - 1][j] == 'O')
                        uf.merge(i * n + j + 1, (i - 1) * n + j + 1);
                    if (j <= n - 2 && board[i][j + 1] == 'O')
                        uf.merge(i * n + j + 1, i * n + j + 2);
                    if (i <= m - 2 && board[i + 1][j] == 'O')
                        uf.merge(i * n + j + 1, (i + 1) * n + j + 1);
                    if (j >= 1 && board[i][j - 1] == 'O')
                        uf.merge(i * n + j + 1, i * n + j);
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'A')
            {
                int root = uf.find(j + 1);
                rec[root] = 1;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (board[m - 1][j] == 'A')
            {
                int root = uf.find((m - 1) * n + j + 1);
                rec[root] = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'A')
            {
                int root = uf.find(i * n + 1);
                rec[root] = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][n - 1] == 'A')
            {
                int root = uf.find(i * n + n);
                rec[root] = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'A')
                {
                    int root = uf.find(i * n + j + 1);
                    if (rec.count(root) || rec.count(i * n + j + 1))
                        board[i][j] = 'O';
                    else
                        board[i][j] = 'X';
                }
            }
        }
    }
};
*/

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                board[i][0] = 'A';
                que.push({i, 0});
            }
            if (board[i][n - 1] == 'O')
            {
                board[i][n - 1] = 'A';
                que.push({i, n - 1});
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
            {
                board[0][j] = 'A';
                que.push({0, j});
            }
            if (board[m - 1][j] == 'O')
            {
                board[m - 1][j] = 'A';
                que.push({m - 1, j});
            }
        }
        while (!que.empty())
        {
            int x = que.front().first, y = que.front().second;
            que.pop();
            if (x >= 1 && board[x - 1][y] == 'O')
            {
                board[x - 1][y] = 'A';
                que.push({x - 1, y});
            }
            if (x <= m - 2 && board[x + 1][y] == 'O')
            {
                board[x + 1][y] = 'A';
                que.push({x + 1, y});
            }
            if (y >= 1 && board[x][y - 1] == 'O')
            {
                board[x][y - 1] = 'A';
                que.push({x, y - 1});
            }
            if (y <= n - 2 && board[x][y + 1] == 'O')
            {
                board[x][y + 1] = 'A';
                que.push({x, y + 1});
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};