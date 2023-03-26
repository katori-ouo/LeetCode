#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;

	void backtracking(int n, int k, int startIdx) {
		if (path.size() == k) {
			res.push_back(path);
			return;
		}
		for (int i = startIdx; i <= n - (k - path.size()) + 1; i++) {
			path.push_back(i);
			backtracking(n, k, i + 1);
			path.pop_back();
		}
	}

	vector<vector<int>> combine(int n, int k) {
		res.clear();
		path.clear();
		backtracking(n, k, 1);
		return res;
	}
};

int main() {
	return 0;
}