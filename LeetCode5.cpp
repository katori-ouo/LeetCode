#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string traversal(const string &s, int i, int j)
    {
        if (j >= s.size())
            return "";
        if (i != j && s[i] != s[j])
            return "";
        int left = i, right = j;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        string str = s.substr(left + 1, right - left - 1);
        return str;
    }

    string longestPalindrome(string s)
    {
        int maxLen = 0;
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            string str1 = traversal(s, i, i);
            string str2 = traversal(s, i, i + 1);
            if (str1.size() > maxLen)
            {
                maxLen = str1.size();
                res = str1;
            }
            if (str2.size() > maxLen)
            {
                maxLen = str2.size();
                res = str2;
            }
        }
        return res;
    }
};