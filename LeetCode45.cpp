#include <iostream>
#include <vector>
using namespace std;
/* 贪心算法 跳跃游戏 */
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int curDistance = 0;
        int ans = 0;
        int nextDistance = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nextDistance = max(nextDistance, nums[i] + i);
            if (i == curDistance)
            {
                if (curDistance < nums.size() - 1)
                {
                    ans++;
                    curDistance = nextDistance;
                    if (nextDistance >= nums.size() - 1)
                        break;
                }
                else
                    break;
            }
        }
        return ans;
    }
};