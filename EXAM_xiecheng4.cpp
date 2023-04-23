#include <iostream>
#include <vector>
using namespace std;

int getNum(long long idx, vector<int> &nums, int n)
{
    idx++;
    for (int i = 0; i < n; i++)
    {
        if (idx - nums[i] <= 0)
        {
            if (i % 2 == 1)
                return 0;
            else
                return 1;
        }
        else
            idx -= nums[i];
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    long long len = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        len += nums[i];
    }
    long long cnt = 0;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (long long i = len - 1; i >= 0; i--)
    {
        for (long long j = i; j < len; j++)
        {
            if (getNum(i, nums, n) == getNum(j, nums, n))
            {
                if (j - i == 1)
                {
                    cnt++;
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1])
                {
                    cnt++;
                    dp[i][j] = true;
                }
            }
        }
    }
    long long temp = 1e9 + 7;
    cnt = cnt % temp;
    cout << cnt << '\n';
}