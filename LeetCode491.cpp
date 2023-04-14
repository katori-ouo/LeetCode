#include <iostream>
#include <vector>
using namespace std;
/* 回溯 所有递增子序列 */
class Solution
{
public:
	vector<vector<int>> res;
	vector<int> path;

	void backtracking(vector<int> &nums, int idx)
	{
		if (path.size() > 1)
		{
			res.push_back(path);
		}
		int used[201] = {0};
		for (int i = idx; i < nums.size(); i++)
		{
			if (used[nums[i] + 100] == 1 || (!path.empty() && nums[i] < path.back()))
			{
				continue;
			}
			used[nums[i] + 100] = 1;
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}

	vector<vector<int>> findSubsequences(vector<int> &nums)
	{
		res.clear();
		path.clear();
		backtracking(nums, 0);
		return res;
	}
};