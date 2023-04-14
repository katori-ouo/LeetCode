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
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
        }
        return dp[(len - 1) % 2][1];
    }
};