#include <iostream>
#include <vector>
using namespace std;
/* 最长递增子序列 */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return 1;
        vector<int> dp(len, 1);
        int res = dp[0];
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};