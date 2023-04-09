#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class State
{
public:
    int x, y;
    int effort;
    State(int x, int y, int effort) : x(x), y(y), effort(effort){};
    bool operator<(const State &rhs) const
    {
        return effort > rhs.effort;
    }
};
class Solution
{
public:
    vector<pair<int, int>> adj(vector<vector<int>> &heights, int x, int y)
    {
        int m = heights.size(), n = heights[0].size();
        vector<pair<int, int>> res;
        if (x >= 1)
            res.push_back({x - 1, y});
        if (x <= m - 2)
            res.push_back({x + 1, y});
        if (y >= 1)
            res.push_back({x, y - 1});
        if (y <= n - 2)
            res.push_back({x, y + 1});
        return res;
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> effortTo(m, vector<int>(n, INT32_MAX));
        effortTo[0][0] = 0;
        priority_queue<State> que;
        que.push(State(0, 0, 0));
        while (!que.empty())
        {
            State curState = que.top();
            que.pop();
            int x = curState.x, y = curState.y;
            int curEffort = curState.effort;
            if (x == m - 1 && y == n - 1)
                return curEffort;
            if (curEffort > effortTo[x][y])
                continue;
            for (auto idx : adj(heights, x, y))
            {
                int nextX = idx.first, nextY = idx.second;
                int nextEffort = max(effortTo[x][y], abs(heights[x][y] - heights[nextX][nextY]));
                if (nextEffort < effortTo[nextX][nextY])
                {
                    effortTo[nextX][nextY] = nextEffort;
                    que.push(State(nextX, nextY, nextEffort));
                }
            }
        }
        return -1;
    }
};