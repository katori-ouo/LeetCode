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

    int countInRange(vector<int> &nums, int lo, int hi, int num)
    {
        int cnt = 0;
        for (int i = lo; i <= hi; i++)
        {
            if (nums[i] == num)
                cnt++;
        }
        return cnt;
    }

    int majorElementRec(vector<int> &nums, int lo, int hi)
    {
        if (lo == hi)
            return nums[lo];
        int mid = lo + (hi - lo) / 2;
        int left = majorElementRec(nums, lo, mid);
        int right = majorElementRec(nums, mid + 1, hi);
        if (left == right)
            return left;
        int leftCount = countInRange(nums, lo, hi, left);
        int rightCount = countInRange(nums, lo, hi, right);
        return leftCount > rightCount ? left : right;
    }

    int majorityElement(vector<int> &nums)
    {
        return majorElementRec(nums, 0, nums.size() - 1);
    }
};