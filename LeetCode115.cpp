#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int lenS = s.size(), lenT = t.size();
        if (lenT > lenS)
            return 0;
        if (lenS == 0)
            return 1;
        vector<vector<uint64_t>> dp(lenS + 1, vector<uint64_t>(lenT + 1, 0));
        for (int i = 0; i <= lenS; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= lenS; i++)
        {
            for (int j = 1; j <= lenT; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[lenS][lenT];
    }
};