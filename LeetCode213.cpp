#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int robRange(vector<int> &nums, int start, int end)
    {
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < end - start + 1; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + start]);
        }
        return dp[end - start];
    }

    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]);
        int res1 = robRange(nums, 0, len - 2);
        int res2 = robRange(nums, 1, len - 1);
        return max(res1, res2);
    }
};