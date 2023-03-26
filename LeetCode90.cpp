#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;

	void backtracking(vector<int>& nums, int idx) {
		res.push_back(path);
		if (idx >= nums.size()) {
			return;
		}
		for (int i = idx; i < nums.size(); i++) {
			if (i > idx && nums[i] == nums[i - 1]) {
				continue;
			}
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		res.clear();
		path.clear();
		sort(nums.begin(), nums.end());
		backtracking(nums, 0);
		return res;
	}
};