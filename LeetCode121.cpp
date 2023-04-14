#include <iostream>
#include <vector>
using namespace std;
/* 买卖股票 */
/**
 * @brief 贪心算法
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT32_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return ans;
    }
};
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
        }
        return dp[(len - 1) % 2][1];
    }
};