#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> res;
	vector<string> path;

	bool isValid(const string &s, int start, int end)
	{
		if (start > end)
			return false;
		if (s[start] == '0' && start != end)
			return false;
		int num = 0;
		for (int i = start; i <= end; i++)
		{
			if (s[i] > '9' || s[i] < '0')
			{
				return false;
			}
			num = 10 * num + s[i] - '0';
			if (num > 255)
			{
				return false;
			}
		}
		return true;
	}

	void backtracking(const string &s, int idx)
	{
		if (path.size() == 3)
		{
			if (isValid(s, idx, s.size() - 1))
			{
				string str = path[0] + "." + path[1] + "." + path[2] + "." + s.substr(idx, s.size() - idx);
				res.push_back(str);
			}
			return;
		}

		//
		for (int i = idx; i < s.size(); i++)
		{
			if (isValid(s, idx, i))
			{
				string temp = s.substr(idx, i - idx + 1);
				path.push_back(temp);
				backtracking(s, i + 1);
				path.pop_back();
			}
			else
			{
				break;
			}
		}
	}

	vector<string> restoreIpAddresses(string s)
	{
		res.clear();
		path.clear();
		backtracking(s, 0);
		return res;
	}
};