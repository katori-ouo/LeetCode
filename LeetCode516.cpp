#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* 最长回文子序列 */
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++)
            dp[i][i] = 1;
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][len - 1];
    }
};