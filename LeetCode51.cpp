#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* 回溯 N皇后 */
class Solution
{
public:
    vector<vector<string>> res;

    bool isValid(int row, int col, vector<string> &board, int n)
    {
        if (row >= n || col >= n)
            return false;
        // 检查同一行
        // for (int i = 0; i < n; i++)
        // {
        //     if (board[row][i] == 'Q')
        //         return false;
        // }
        // 检查同一列
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查45度
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查135度
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void backtracking(vector<string> &board, int row, int n)
    {
        if (row == n)
        {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, board, n))
            {
                board[row][col] = 'Q';
                backtracking(board, row + 1, n);
                board[row][col] = '.';
            }
            else
            {
                continue;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        // 初始化棋盘
        vector<string> board(n, string(n, '.'));
        res.clear();
        backtracking(board, 0, n);
        return res;
    }
};