#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int len = 0;
        int left = 0, right = 0;
        int cnt = 0;
        for (; right < nums.size(); right++)
        {
            if (nums[right] == 0)
                cnt++;
            while (cnt > k)
            {
                if (nums[left] == 0)
                    cnt--;
                left++;
            }
            len = len > (right - left + 1) ? len : right - left + 1;
        }
        return len;
    }
};