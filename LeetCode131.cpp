#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:

	vector<vector<string>> res;
	vector<string> path;

	bool isValid(const string& s, int start, int end) {
		if (start > end) return false;
		for (int i = start, j = end; i < j; i++, j--) {
			if (s[i] != s[j]) return false;
		}
		return true;
	}

	void backtracking(const string& s, int idx) {
		// Í£Ö¹Âß¼­
		if (idx >= s.size()) {
			res.push_back(path);
			return;
		}
		// µ±Ç°²ã
		for (int i = idx; i < s.size(); i++) {
			if (isValid(s, idx, i)) {
				string temp = s.substr(idx, i - idx + 1);
				path.push_back(temp);
			}
			else {
				continue;
			}
			backtracking(s, i + 1);
			path.pop_back();
		}
	}

	vector<vector<string>> partition(string s) {
		res.clear();
		path.clear();
		backtracking(s, 0);
		return res;
	}
};

int main() {
	return 0;
}