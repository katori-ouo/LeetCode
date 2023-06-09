#include <iostream>
#include <vector>
using namespace std;
/* 完全背包 零钱兑换 */
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] == INT32_MAX)
                    continue;
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == INT32_MAX)
            return -1;
        return dp[amount];
    }
};