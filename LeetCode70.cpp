#include <iostream>
#include <vector>
using namespace std;
/* 完全背包 爬楼梯*/
/**
 * @brief 普通动态规划题解,爬楼梯阶数为1/2
class Solution
{
public:
    int climbStairs(int n)
    {
        int p = 1, q = 1;
        int ans = 1;
        if (n <= 1)
            return ans;
        for (int i = 1; i < n; i++)
        {
            ans = p + q;
            p = q;
            q = ans;
        }
        return ans;
    }
};
*/

class Solution
{
public:
    /**
     * @brief 利用背包问题解决爬楼梯
     *
     * @param n 楼梯数
     * @param m 每次最多爬几阶
     * @return int 爬楼梯方案的个数
     */
    int mStairs(int n, int m)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m && j <= i; j++)
            {
                dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }

    int climbStairs(int n)
    {
        return mStairs(n, 2);
    }
};