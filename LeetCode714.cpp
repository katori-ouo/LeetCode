#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int len = prices.size();
        if (len == 1)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] -= prices[0];
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[len - 1][0], dp[len - 1][1]);
    }
};