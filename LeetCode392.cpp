#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    /*
    双指针法
    bool isSubsequence(string s, string t)
    {
        int lens = s.size(), lent = t.size();
        if (lens > lent)
            return false;
        if (lens == lent && lens == 0)
            return true;
        int ptrS = 0, ptrT = 0;
        for (; ptrT < lent; ptrT++)
        {
            if (t[ptrT] == s[ptrS])
                ptrS++;
            if (ptrS == lens)
                return true;
        }
        return false;
    }
    */
    bool isSubsequence(string s, string t)
    {
        int lenS = s.size(), lenT = t.size();
        if (lenS > lenT)
            return false;
        if (lenS == 0 && lenT == 0)
            return true;
        vector<vector<int>> dp(lenS + 1, vector<int>(lenT + 1, 0));
        for (int i = 1; i <= lenS; i++)
        {
            for (int j = 1; j <= lenT; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        if (dp[lenS][lenT] == lenS)
            return true;
        return false;
    }
};