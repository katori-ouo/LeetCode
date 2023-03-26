#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	int sum = 0;

	void backtracking(int k, int n, int sum, int idx) {
		if (sum > n) {
			return;
		}
		if (path.size() == k) {
			if (sum == n) {
				res.push_back(path);
			}
			return;
		}
		for (int i = idx; i <= 9 - (k - path.size()) + 1; i++) {
			path.push_back(i);
			sum += i;
			backtracking(k, n, sum, i + 1);
			path.pop_back();
			sum -= i;
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		res.clear();
		path.clear();
		sum = 0;
		backtracking(k, n, sum, 1);
		return res;
	}
};

int main() {
	return 0;
}