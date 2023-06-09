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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        UnionFind uf;
        for (int i = 0; i < isConnected.size(); i++)
        {
            uf.add(i);
            for (int j = 0; j < i; j++)
            {
                if (isConnected[i][j])
                {
                    uf.merge(i, j);
                }
            }
        }
        return uf.getCnt();
    }
};