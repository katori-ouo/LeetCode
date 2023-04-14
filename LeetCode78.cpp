#include <iostream>
#include <vector>
using namespace std;
/* 回溯 集合的所有子集 */
class Solution
{
public:
	vector<vector<int>> res;
	vector<int> path;
	void backtracking(vector<int> &nums, int idx)
	{
		res.push_back(path);
		if (idx >= nums.size())
		{
			return;
		}
		for (int i = idx; i < nums.size(); i++)
		{
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int> &nums)
	{
		res.clear();
		path.clear();
		backtracking(nums, 0);
		return res;
	}
};