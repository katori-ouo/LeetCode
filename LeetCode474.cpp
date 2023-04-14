#include <iostream>
#include <vector>
using namespace std;
/* 0-1背包 字符串集合1和0的个数*/
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs)
        {
            int oneNum = 0, zeroNum = 0;
            for (char c : str)
            {
                if (c == '0')
                    zeroNum++;
                else
                    oneNum++;
            }
            for (int i = m; i >= zeroNum; i--)
            {
                for (int j = n; j >= oneNum; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};