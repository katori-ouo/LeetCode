#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxKilledEnemies(vector<vector<char>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int pre = 0;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            pre = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'E')
                    pre++;
                else if (grid[i][j] == 'W')
                    pre = 0;
                else if (grid[i][j] == '0')
                    dp[i][j] += pre;
            }
            pre = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 'E')
                    pre++;
                else if (grid[i][j] == 'W')
                    pre = 0;
                else if (grid[i][j] = '0')
                    dp[i][j] += pre;
            }
        }
        for (int j = 0; j < n; j++)
        {
            pre = 0;
            for (int i = 0; i < m; i++)
            {
                if (grid[i][j] == 'E')
                    pre++;
                else if (grid[i][j] == 'W')
                    pre = 0;
                else if (grid[i][j] == '0')
                    dp[i][j] += pre;
            }
            pre = 0;
            for (int i = m - 1; i >= 0; i--)
            {
                if (grid[i][j] == 'E')
                    pre++;
                else if (grid[i][j] == 'W')
                    pre = 0;
                else if (grid[i][j] == '0')
                    dp[i][j] += pre;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '0')
                {
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<char>> grid = {{'0', 'E', '0', '0'},
                                 {'E', '0', 'W', 'E'},
                                 {'0', 'E', '0', '0'}};
    Solution solve;
    int num = solve.maxKilledEnemies(grid);
    return 0;
}