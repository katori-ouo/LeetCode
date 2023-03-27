#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int len = nums.size();
        // 求前缀和数组
        vector<int> preSum(len + 1, 0);
        for (int i = 0; i < len; i++)
        {
            preSum[i + 1] = nums[i] + preSum[i];
        }
        for (int i = 0; i < len; i++)
        {
            int leftSum = preSum[i];
            int rightSum = preSum[len] - preSum[i + 1];
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }
};