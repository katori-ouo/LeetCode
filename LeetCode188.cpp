#include <iostream>
#include <vector>
using namespace std;
/* 买卖股票 */
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int len = prices.size();
        if (len == 1)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k; j += 2)
        {
            dp[0][j] -= prices[0];
        }
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j < 2 * k; j += 2)
            {
                // 买入/卖出第(j+1)/2支股票
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
            }
        }
        return dp[len - 1][2 * k];
    }
};