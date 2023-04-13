#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(const int& a, const int& b)
{
	return a > b;
}

int main()
{
	int n, x;
	cin >> n >> x;
	vector<int> scores(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];
	}
	sort(scores.begin(), scores.end(), cmp);
	if (x > n || x == 0)
	{
		cout << 0 << '\n';
		return 0;
	}
	if (scores[x - 1] == 0)
	{
		while (x >= 1 && scores[x - 1] == 0)
		{
			x--;
		}
		cout << x << '\n';
		return 0;
	}
	while (x < n && scores[x] == scores[x - 1])
	{
		x++;
	}
	cout << x << '\n';
	return 0;
}