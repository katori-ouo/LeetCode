#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else if (nums[mid] < nums[right])
            right = mid;
        else
            right = mid;
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {2, 3, 4};
    int res = findMin(nums);
    printf("%d", res);
    return 0;
}