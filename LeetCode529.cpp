#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int count(vector<vector<char>> &board, int x, int y)
    {
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        if (x >= 1)
        {
            if (y >= 1 && board[x - 1][y - 1] == 'M')
                cnt++;
            if (board[x - 1][y] == 'M')
                cnt++;
            if (y <= n - 2 && board[x - 1][y + 1] == 'M')
                cnt++;
        }
        if (x <= m - 2)
        {
            if (y >= 1 && board[x + 1][y - 1] == 'M')
                cnt++;
            if (board[x + 1][y] == 'M')
                cnt++;
            if (y <= n - 2 && board[x + 1][y + 1] == 'M')
                cnt++;
        }
        if (y >= 1 && board[x][y - 1] == 'M')
            cnt++;
        if (y <= n - 2 && board[x][y + 1] == 'M')
            cnt++;
        return cnt;
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int m = board.size();
        int n = board[0].size();
        int x = click[0], y = click[1];
        vector<vector<bool>> canUse(m, vector<bool>(n, true));
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }
        if (board[x][y] == 'B' || (board[x][y] >= '1' && board[x][y] <= '8') || board[x][y] == 'X')
            return board;
        queue<pair<int, int>> que;
        canUse[x][y] = false;
        que.push({x, y});
        int num = 0;
        while (!que.empty())
        {
            int x = que.front().first, y = que.front().second;
            que.pop();
            if (board[x][y] == 'M')
                continue;
            num = count(board, x, y);
            if (num != 0)
                board[x][y] = num + '0';
            else
            {
                board[x][y] = 'B';
                if (x >= 1 && y >= 1)
                {
                    num = count(board, x - 1, y - 1);
                    if (num == 0)
                    {
                        if (canUse[x - 1][y - 1])
                        {
                            canUse[x - 1][y - 1] = false;
                            board[x - 1][y - 1] = 'B';
                            que.push({x - 1, y - 1});
                        }
                    }
                    else
                        board[x - 1][y - 1] = num + '0';
                }
                if (x >= 1 && y <= n - 2)
                {
                    num = count(board, x - 1, y + 1);
                    if (num == 0)
                    {
                        if (canUse[x - 1][y + 1])
                        {
                            canUse[x - 1][y + 1] = false;
                            board[x - 1][y + 1] = 'B';
                            que.push({x - 1, y + 1});
                        }
                    }
                    else
                        board[x - 1][y + 1] = num + '0';
                }
                if (x >= 1)
                {
                    num = count(board, x - 1, y);
                    if (num == 0)
                    {
                        if (canUse[x - 1][y])
                        {
                            canUse[x - 1][y] = false;
                            board[x - 1][y] = 'B';
                            que.push({x - 1, y});
                        }
                    }
                    else
                        board[x - 1][y] = num + '0';
                }
                if (y >= 1)
                {
                    num = count(board, x, y - 1);
                    if (num == 0)
                    {
                        if (canUse[x][y - 1])
                        {
                            canUse[x][y - 1] = false;
                            board[x][y - 1] = 'B';
                            que.push({x, y - 1});
                        }
                    }
                    else
                        board[x][y - 1] = num + '0';
                }
                if (y <= n - 2)
                {
                    num = count(board, x, y + 1);
                    if (num == 0)
                    {
                        if (canUse[x][y + 1])
                        {
                            canUse[x][y + 1] = false;
                            board[x][y + 1] = 'B';
                            que.push({x, y + 1});
                        }
                    }
                    else
                        board[x][y + 1] = num + '0';
                }
                if (x <= m - 2 && y >= 1)
                {
                    num = count(board, x + 1, y - 1);
                    if (num == 0)
                    {
                        if (canUse[x + 1][y - 1])
                        {
                            canUse[x + 1][y - 1] = false;
                            board[x + 1][y - 1] = 'B';
                            que.push({x + 1, y - 1});
                        }
                    }
                    else
                        board[x + 1][y - 1] = num + '0';
                }
                if (x <= m - 2 && y <= n - 2)
                {
                    num = count(board, x + 1, y + 1);
                    if (num == 0)
                    {
                        if (canUse[x + 1][y + 1])
                        {
                            canUse[x + 1][y + 1] = false;
                            board[x + 1][y + 1] = 'B';
                            que.push({x + 1, y + 1});
                        }
                    }
                    else
                        board[x + 1][y + 1] = num + '0';
                }
                if (x <= m - 2)
                {
                    num = count(board, x + 1, y);
                    if (num == 0)
                    {
                        if (canUse[x + 1][y])
                        {
                            canUse[x + 1][y] = false;
                            board[x + 1][y] = 'B';
                            que.push({x + 1, y});
                        }
                    }
                    else
                        board[x + 1][y] = num + '0';
                }
            }
        }
        return board;
    }
};

int main()
{
    vector<vector<char>> board = {{'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'M'}};
    Solution sl;
    vector<int> click = {0, 0};
    sl.updateBoard(board, click);
    return 0;
}
