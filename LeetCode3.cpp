#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> cnt;
        int left = 0, right = 0;
        int len = 0;
        for (; right < s.size(); right++)
        {
            char c = s[right];
            cnt[c]++;
            while (cnt[c] > 1)
            {
                cnt[s[left]]--;
                left++;
            }
            len = len > (right - left + 1) ? len : right - left + 1;
        }
        return len;
    }
};