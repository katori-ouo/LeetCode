#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 回溯 组合总和 */
class Solution
{
public:
	vector<vector<int>> res;
	vector<int> path;
	int sum;

	void backtracking(vector<int> &candidates, int target, int sum, int idx)
	{
		if (sum == target)
		{
			res.push_back(path);
			return;
		}
		for (int i = idx; i < candidates.size() && sum + candidates[i] <= target; i++)
		{
			if (i > idx && candidates[i] == candidates[i - 1])
			{
				continue;
			}
			sum += candidates[i];
			path.push_back(candidates[i]);
			backtracking(candidates, target, sum, i + 1);
			sum -= candidates[i];
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
	{
		res.clear();
		path.clear();
		sum = 0;
		sort(candidates.begin(), candidates.end());
		backtracking(candidates, target, sum, 0);
		return res;
	}
};