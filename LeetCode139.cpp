#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if (dp[j] && find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
                {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};