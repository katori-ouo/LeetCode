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
};

class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> indegree(n + 1, 0);
        bool cycle = true;
        vector<vector<int>> rec;
        for (int i = 0; i < n; i++)
        {
            int to = edges[i][1];
            indegree[to]++;
            if (indegree[to] == 2)
            {
                cycle = false;
                for (int j = 0; j < i; j++)
                {
                    if (edges[j][1] == to)
                        rec.push_back(edges[j]);
                }
                rec.push_back(edges[i]);
                break;
            }
        }
        if (cycle)
        {
            UnionFind uf;
            for (int i = 0; i < n; i++)
            {
                uf.add(edges[i][0]);
                uf.add(edges[i][1]);
                if (uf.isConnected(edges[i][0], edges[i][1]))
                    return edges[i];
                else
                    uf.merge(edges[i][0], edges[i][1]);
            }
        }
        else
        {
            UnionFind uf;
            for (int i = 0; i < n; i++)
            {
                if (edges[i] == rec[1])
                    continue;
                uf.add(edges[i][0]);
                uf.add(edges[i][1]);
                if (uf.isConnected(edges[i][0], edges[i][1]))
                    return rec[0];
                else
                    uf.merge(edges[i][0], edges[i][1]);
            }
            return rec[1];
        }
        return {0, 0};
    }
};