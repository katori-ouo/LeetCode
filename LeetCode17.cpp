#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* 回溯 电话号码映射字母 */
class Solution
{
private:
	const string letterMap[10] = {
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz",
	};

public:
	vector<string> res;
	string s;

	void backtracking(const string &digits, int idx)
	{
		if (idx == digits.size())
		{
			res.push_back(s);
			return;
		}
		int num = digits[idx] - '0';
		string temp = letterMap[num];
		for (int i = 0; i < temp.size(); i++)
		{
			s.push_back(temp[i]);
			backtracking(digits, idx + 1);
			s.pop_back();
		}
	}

	vector<string> letterCombinations(string digits)
	{
		res.clear();
		s.clear();
		if (digits.size() == 0)
		{
			return res;
		}
		backtracking(digits, 0);
		return res;
	}
};

int main()
{
	return 0;
}