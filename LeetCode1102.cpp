#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class State
{
public:
    int x, y;
    int score;
    State(int x, int y, int s) : x(x), y(y), score(s) {}
    bool operator<(const State &rhs) const
    {
        return score < rhs.score;
    }
};

class Solution
{
public:
    vector<pair<int, int>> adj(vector<vector<int>> &A, int x, int y)
    {
        int m = A.size(), n = A[0].size();
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

    int maximumMinimumPath(vector<vector<int>> &A)
    {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> sTo(m, vector<int>(n, 0));
        sTo[0][0] = A[0][0];
        priority_queue<State> que;
        que.push(State(0, 0, sTo[0][0]));
        while (!que.empty())
        {
            State curNode = que.top();
            que.pop();
            int x = curNode.x, y = curNode.y;
            int curScore = curNode.score;
            if (x == m - 1 && y == n - 1)
            {
                return curScore;
            }
            if (curScore < sTo[x][y])
                continue;
            for (auto idx : adj(A, x, y))
            {
                int nextX = idx.first, nextY = idx.second;
                int nextScore = min(A[nextX][nextY], sTo[x][y]);
                if (nextScore > sTo[nextX][nextY])
                {
                    sTo[nextX][nextY] = nextScore;
                    que.push(State(nextX, nextY, nextScore));
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> A = {{3, 4, 6, 3, 4},
                             {0, 2, 1, 1, 7},
                             {8, 8, 3, 2, 7},
                             {3, 2, 4, 9, 8},
                             {4, 1, 2, 0, 0},
                             {4, 6, 5, 4, 3}};
    Solution solve;
    int ans = solve.maximumMinimumPath(A);
    return 0;
}