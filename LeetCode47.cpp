#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 回溯 数组的全排列 */
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == true || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false))
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return res;
    }
};