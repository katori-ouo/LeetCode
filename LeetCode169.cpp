#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
    int majorityElement(vector<int> &nums)
    {
        int res = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == res)
                cnt++;
            else
                cnt--;
            if (cnt == 0)
            {
                cnt = 1;
                res = nums[i];
            }
        }
        return res;
    }
    */

    int cnt(vector<int> &nums, int left, int right, int num)
    {
        int cnt = 0;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] == num)
                cnt++;
        }
        return cnt;
    }

    int majorityElementRange(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int leftNum = majorityElementRange(nums, left, mid);
        int rightNum = majorityElementRange(nums, mid + 1, right);
        if (leftNum == rightNum)
            return leftNum;
        else
        {
            int leftCnt = cnt(nums, left, right, leftNum);
            int rightCnt = cnt(nums, left, right, rightNum);
            return leftCnt > rightCnt ? leftNum : rightNum;
        }
    }

    int majorityElement(vector<int> &nums)
    {
        return majorityElementRange(nums, 0, nums.size() - 1);
    }
};