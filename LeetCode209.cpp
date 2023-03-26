#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int len = INT32_MAX;
    int sum = 0;
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 0;
        for (; right < nums.size(); right++)
        {
            sum += nums[right];
            if (sum >= target)
            {
                while (sum - nums[left] >= target)
                {
                    sum -= nums[left];
                    left++;
                }
                int temp = right - left + 1;
                len = len > temp ? temp : len;
            }
        }
        return len == INT32_MAX ? 0 : len;
    }
};