#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
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
};