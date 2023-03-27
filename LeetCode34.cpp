#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getLeft(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (left >= nums.size())
            return -1;
        if (nums[left] == target)
            return left;
        return -1;
    }

    int getRight(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                left = mid + 1;
        }
        if (right < 0)
            return -1;
        if (nums[right] == target)
            return right;
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = getLeft(nums, target);
        int right = getRight(nums, target);
        vector<int> ans = {left, right};
        return ans;
    }
};