#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* 回文子串个数 */
/*
双指针法
class Solution
{
public:
    int cnt;
    void count(string s, int left, int right)
    {
        for (int i = left, j = right; i >= 0 && j < s.size(); i--, j++)
        {
            if (s[i] == s[j])
                cnt++;
            else
                break;
        }
    }
    int countSubstrings(string s)
    {
        cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            count(s, i, i);
            count(s, i, i + 1);
        }
        return cnt;
    }
};
*/

class Solution
{
public:
    int countSubstrings(string s)
    {
        int cnt = 0;
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i; j < len; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
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
        return cnt;
    }
};