#include <iostream>
#include <vector>
using namespace std;
/* 完全背包 完全平方数 */
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++)
        {
            for (int j = i * i; j <= n; j++)
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};