#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 1)
            return len;
        vector<int> dp(len, 1);
        int res = 1;
        for (int i = 1; i < len; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};