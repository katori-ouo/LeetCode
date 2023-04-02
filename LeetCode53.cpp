#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
    贪心算法
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT32_MIN;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cnt += nums[i];
            if (cnt > ans)
                ans = cnt;
            if (cnt <= 0)
                cnt = 0;
        }
        return ans;
    }
    */
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};