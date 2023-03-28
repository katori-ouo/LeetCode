#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char val)
    {
        if (row >= 9 || col >= 9)
            return false;
        // 检查同一行
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == val)
                return false;
        }
        // 检查同一列
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == val)
                return false;
        }
        // 检查3*3宫内
        int x = row / 3 + 1;
        int y = col / 3 + 1;
        for (int i = (x - 1) * 3; i < x * 3; i++)
        {
            for (int j = (y - 1) * 3; j < y * 3; j++)
            {
                if (board[i][j] == val)
                    return false;
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isValid(board, i, j, k))
                        {
                            board[i][j] = k;
                            if (backtracking(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }
};