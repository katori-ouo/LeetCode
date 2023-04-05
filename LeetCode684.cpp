#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionFind
{
private:
    unordered_map<int, int> father;

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
        }
    }

    void merge(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            father[rootX] = rootY;
        }
    }

    void isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        UnionFind uf;
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            uf.add(x);
            uf.add(y);
            if (uf.isConnected(x, y))
                return edges[i];
            else
            {
                uf.merge(x, y);
            }
        }
        return edges[0];
    }
};