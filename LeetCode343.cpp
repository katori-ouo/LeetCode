#include <iostream>
#include <vector>
using namespace std;
/* 整数拆分 乘积最大化*/
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};