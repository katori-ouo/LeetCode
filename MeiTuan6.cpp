#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	if (2 * x > n || 2 * y < n)
		return -1;
	vector<int> scores(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];
	}
	sort(scores.begin(), scores.end());
	int left = max(n - y, x) - 1;
	int right = min(n - x, y) - 1;
	int ans = left;
	while (ans + 1 < n && scores[ans + 1] == scores[left])
	{
		ans++;
	}
	if (ans > right)
		cout << -1 << '\n';
	else
		cout << scores[ans] << '\n';
	return 0;
}