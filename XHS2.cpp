#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vals(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = vals[0];
    dp[0][1] = 1;
    dp[1][0] = max(vals[0], vals[1]);
    dp[1][1] = 1;
    int maxVal = dp[1][0];
    int cnt = 1;
    for (int i = 2; i < n; i++)
    {
        int temp1 = dp[i - 2][0] + vals[i];
        int temp2 = dp[i - 1][0];
        if (temp1 > temp2)
        {
            dp[i][0] = temp1;
            dp[i][1] = dp[i - 2][1] + 1;
        }
        else if (temp1 < temp2)
        {
            dp[i][0] = temp2;
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            dp[i][0] = temp1;
            dp[i][1] = min(dp[i - 2][1] + 1, dp[i - 1][1]);
        }
        if (maxVal < dp[i][0])
        {
            maxVal = dp[i][0];
            cnt = dp[i][1];
        }
        else if (maxVal == dp[i][0])
        {
            cnt = min(cnt, dp[i][1]);
        }
    }
    cout << maxVal << " " << cnt << '\n';
}