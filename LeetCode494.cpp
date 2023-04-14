#include <iostream>
#include <vector>
using namespace std;
/* 0-1背包 目标和*/
/**
 * 回溯算法,暴力求解
class Solution
{
public:
    int res;
    void backtracking(vector<int> &nums, int idx, int sum, int target)
    {
        if (idx == nums.size())
        {
            if (sum == target)
                res++;
            return;
        }
        sum += nums[idx];
        backtracking(nums, idx + 1, sum, target);
        sum -= 2 * nums[idx];
        backtracking(nums, idx + 1, sum, target);
        sum += nums[idx];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        res = 0;
        backtracking(nums, 0, 0, target);
        return res;
    }
};
*/

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (abs(target) > sum)
            return 0;
        if ((sum + target) % 2 == 1)
            return 0;
        int bagSize = (sum + target) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = bagSize; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};