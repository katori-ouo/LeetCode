#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, uint64_t> mp;
uint64_t numDistinct(string &s, string &t)
{
    int lens = s.size();
    int lent = t.size();
    if (lent > lens)
        return 0;
    if (lens == 0)
        return 1;
    vector<vector<uint64_t>> dp(lens + 1, vector<uint64_t>(lent + 1, 0));
    for (int i = 0; i <= lens; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= lens; i++)
    {
        for (int j = 1; j <= lent; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[lens][lent];
}

uint64_t sumVal(string &s, string &t, int n)
{
    uint64_t sum = 0;
    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            string temp = s.substr(i, j - i + 1);
            if (mp.count(temp))
            {
                sum += mp[temp];
            }
            else
            {
                uint64_t val = numDistinct(temp, t);
                sum += val;
                mp[temp] = val;
            }
        }
    }
    return sum;
}

void dfs(int n, string &s, string &t, uint64_t &cnt)
{
    if (s.size() == n)
    {
        cnt += sumVal(s, t, n);
        return;
    }
    s += 'r';
    dfs(n, s, t, cnt);
    s.pop_back();
    s += 'e';
    dfs(n, s, t, cnt);
    s.pop_back();
    s += 'd';
    dfs(n, s, t, cnt);
    s.pop_back();
}

int main()
{
    int n;
    cin >> n;
    uint64_t cnt = 0;
    string s = "";
    string t = "red";
    dfs(n, s, t, cnt);
    uint64_t temp = 1e9 + 7;
    cnt = cnt % temp;
    cout << cnt << '\n';
}