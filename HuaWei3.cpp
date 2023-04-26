#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;
string s;
vector<bool> used;
int len = 0;

void backtracking(string& path)
{
	if (path.size() == len)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < len; i++)
	{
		if (used[i] == true || (i > 0 && s[i] == s[i - 1] && used[i - 1] == false))
		{
			continue;
		}
		path.push_back(s[i]);
		used[i] = true;
		backtracking(path);
		path.pop_back();
		used[i] = false;
	}
}

int main()
{
	getline(cin, s);
	len = s.size();
	sort(s.begin(), s.end());
	used.resize(len, false);
	string path = "";
	backtracking(path);
	cout << cnt << '\n';
}