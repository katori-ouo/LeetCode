#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class State
{
public:
    int x, y;
    int time;
    State(int x, int y, int time) : x(x), y(y), time(time) {}
    bool operator<(const State &rhs) const
    {
        return time > rhs.time;
    }
};

/**
 * @brief 判断在十字路口能往什么方向走
 *
 * @param t 时间
 * @param a a属性
 * @param b b属性
 * @return true i+-1,j方向
 * @return false i,j+-1方向
 */
bool chooseDirection(int t, int a, int b)
{
    int res = t % (a + b);
    if (res >= 0 && res < a)
        return true;
    if (res >= a && res < a + b)
        return false;
    return false;
}

vector<pair<int, int>> adj(int n, int m, int x, int y)
{
    vector<pair<int, int>> res;
    if (x >= 1)
        res.push_back({x - 1, y});
    if (x <= n - 2)
        res.push_back({x + 1, y});
    if (y >= 1)
        res.push_back({x, y - 1});
    if (y <= m - 2)
        res.push_back({x, y + 1});
    return res;
}

int main()
{
    int n, m; // n*m个十字路口
    cin >> n >> m;
    int xs, ys; // 小美的初始位置
    int xt, yt; // 小团的初始位置
    cin >> xs >> ys >> xt >> yt;
    xs--;
    ys--;
    xt--;
    yt--;
    vector<vector<int>> A(n, vector<int>(m, 0)); // a_ij
    vector<vector<int>> B(n, vector<int>(m, 0)); // b_ij
    int ansTime = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> B[i][j];
        }
    }
    // 从小美初始位置到每个地方的最小时间
    vector<vector<int>> timeTo(n, vector<int>(m, INT32_MAX));
    int temp;
    timeTo[xs][ys] = 0;
    priority_queue<State> que;
    que.push(State(xs, ys, 0));
    while (!que.empty())
    {
        State curState = que.top();
        que.pop();
        int x = curState.x, y = curState.y;
        int curTime = curState.time;
        if (x == xt && y == yt)
        {
            ansTime = curTime;
            break;
        }
        if (curTime > timeTo[x][y])
            continue;
        temp = curTime % (A[x][y] + B[x][y]);
        if (temp < A[x][y])
        {
            if (x >= 1)
            {
                int nextX = x - 1, nextY = y;
                int nextTime = min(timeTo[nextX][nextY], curTime + 1);
                if (nextTime < timeTo[nextX][nextY])
                {
                    timeTo[nextX][nextY] = nextTime;
                    que.push(State(nextX, nextY, nextTime));
                }
            }
            if (x <= n - 2)
            {
                int nextX = x + 1, nextY = y;
                int nextTime = min(timeTo[nextX][nextY], curTime + 1);
                if (nextTime < timeTo[nextX][nextY])
                {
                    timeTo[nextX][nextY] = nextTime;
                    que.push(State(nextX, nextY, nextTime));
                }
            }
            if (y >= 1)
            {
                int nextX = x, nextY = y - 1;
                int nextTime = min(timeTo[nextX][nextY], curTime + A[x][y] - temp + 1);
                if (nextTime < timeTo[nextX][nextY])
                {
                    timeTo[nextX][nextY] = nextTime;
                    que.push(State(nextX, nextY, nextTime));
                }
            }
            if (y <= m - 2)
            {
                int nextX = x, nextY = y + 1;
                int nextTime = min(timeTo[nextX][nextY], curTime + A[x][y] - temp + 1);
                if (nextTime < timeTo[nextX][nextY])
                {
                    timeTo[nextX][nextY] = nextTime;
                    que.push(State(nextX, nextY, nextTime));
                }
            }
        }
        else if (temp >= A[x][y] && temp < A[x][y] + B[x][y])
        {
            if (x >= 1)
            {
                int nextX = x - 1, nextY = y;
                int nextTime = min(timeTo[nextX][nextY], curTime + A[x][y] + B[x][y] - temp + 1);
                if (nextTime < timeTo[nextX][nextY])
                {
                    timeTo[nextX][nextY] = nextTime;
                    que.push(State(nextX, nextY, nextTime));
                }
            }
            if (x <= n - 2)
            {
                int nextX = x + 1, nextY = y;
                int nextTime = min(timeTo[nextX][nextY], curTime + A[x][y] + B[x][y] - temp + 1);
                if (nextTime < timeTo[nextX][nextY])
                {
                    timeTo[nextX][nextY] = nextTime;
                    que.push(State(nextX, nextY, nextTime));
                }
            }
            if (y >= 1)
            {
                int nextX = x, nextY = y - 1;
                int nextTime = min(timeTo[nextX][nextY], curTime + 1);
                if (nextTime < timeTo[nextX][nextY])
                {
                    timeTo[nextX][nextY] = nextTime;
                    que.push(State(nextX, nextY, nextTime));
                }
            }
            if (y <= m - 2)
            {
                int nextX = x, nextY = y + 1;
                int nextTime = min(timeTo[nextX][nextY], curTime + 1);
                if (nextTime < timeTo[nextX][nextY])
                {
                    timeTo[nextX][nextY] = nextTime;
                    que.push(State(nextX, nextY, nextTime));
                }
            }
        }
    }
    cout << ansTime << '\n';
}