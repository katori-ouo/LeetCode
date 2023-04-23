#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class State
{
public:
    int x, y;
    int cnt;
    State(int x, int y, int l) : x(x), y(y), cnt(l) {}
    bool operator<(const State &rhs) const
    {
        return cnt > rhs.cnt;
    }
};

vector<pair<int, int>> adj(int n, int x, int y)
{
    vector<pair<int, int>> res;
    if (x >= 1)
        res.push_back({x - 1, y});
    else if (x == 0)
        res.push_back({n - 1, y});
    if (x <= n - 2)
        res.push_back({x + 1, y});
    else if (x == n - 1)
        res.push_back({0, y});
    if (y >= 1)
        res.push_back({x, y - 1});
    else if (y == 0)
        res.push_back({x, n - 1});
    if (y <= n - 2)
        res.push_back({x, y + 1});
    else if (y == n - 1)
        res.push_back({x, 0});
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    char c;
    int sx = 0, sy = 0, ex = 0, ey = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            grid[i][j] = c;
            if (c == 'S')
            {
                sx = i;
                sy = j;
            }
            if (c == 'E')
            {
                ex = i;
                ey = j;
            }
        }
    }
    vector<vector<int>> disTo(n, vector<int>(n, INT32_MAX));
    disTo[sx][sy] = 0;
    priority_queue<State> que;
    que.push(State(sx, sy, 0));
    while (!que.empty())
    {
        State curState = que.top();
        que.pop();
        int x = curState.x, y = curState.y;
        int curDis = curState.cnt;
        if (x == ex && y == ey)
        {
            cout << curDis << '\n';
            return 0;
        }
        if (curDis > disTo[x][y])
            continue;
        for (auto idx : adj(n, x, y))
        {
            int nextX = idx.first, nextY = idx.second;
            if (grid[nextX][nextY] == '#')
                continue;
            int nextDis = curDis + 1;
            if (nextDis < disTo[nextX][nextY])
            {
                disTo[nextX][nextY] = nextDis;
                que.push(State(nextX, nextY, nextDis));
            }
        }
    }
    cout << -1 << '\n';
}