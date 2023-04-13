#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int len;
	cin >> len;
	string s;
	cin >> s;
	vector<int> dp(len, 0);
	int ans = INT32_MIN;
	if (s[0] == 'E')
		dp[0] = 1;
	else if (s[0] == 'F')
		dp[0] = 0;
	for (int i = 1; i < len; i++)
	{
		if (s[i] == 'E')
		{
			dp[i] = max(1, dp[i - 1] + 1);
		}
		else if (s[i] == 'F')
		{
			dp[i] = max(0, dp[i - 1] - 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}