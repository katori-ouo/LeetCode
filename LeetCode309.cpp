#include <iostream>
#include <vector>
using namespace std;
/* 卖卖股票 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len == 1)
            return 0;
        vector<vector<int>> dp(len, vector<int>(4, 0));
        /*
        NOTE:
        j=0:持有股票
        j=1:卖出股票，且不在冷冻期
        j=2:今天卖出股票
        j=3:处于冷冻期
        */
        dp[0][0] -= prices[0];
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[len - 1][1], max(dp[len - 1][2], dp[len - 1][3]));
    }
};