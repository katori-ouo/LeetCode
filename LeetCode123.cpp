#include <iostream>
#include <vector>
using namespace std;
/* 买卖股票 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len == 0)
            return 0;
        /**
        NOTE:
        状态0：没有操作
        状态1：第一次有股票
        状态2：第一次卖股票
        状态3：第二次有股票
        状态4：第二次卖股票
        dp[i][j]表示第i天状态j所剩最大现金
        */
        vector<vector<int>> dp(len, vector<int>(5, 0));
        dp[0][0] = 0;
        dp[0][1] -= prices[0];
        dp[0][2] = 0;
        dp[0][3] -= prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[len - 1][4];
    }
};