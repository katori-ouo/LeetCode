#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getLeft(vector<int> &nums, int target)
    {
        int len = nums.size() - 1;
        int left = 0, right = len, mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        if (left > len || nums[left] != target)
            return -1;
        return left;
    }

    int getRight(vector<int> &nums, int target)
    {
        int len = nums.size() - 1;
        int left = 0, right = len, mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }
        if (right < 0 || nums[right] != target)
            return -1;
        return right;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = getLeft(nums, target);
        int right = getRight(nums, target);
        vector<int> res = {left, right};
        return res;
    }
};