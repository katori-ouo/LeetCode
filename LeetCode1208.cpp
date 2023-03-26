#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int len = 0;
        int left = 0, right = 0;
        int subCost = 0;
        if (s.size() != t.size())
            return 0;
        for (; right < t.size(); right++)
        {
            subCost += abs(s[right] - t[right]);
            while (subCost > maxCost)
            {
                subCost -= abs(s[left] - t[left]);
                left++;
            }
            len = len > (right - left + 1) ? len : right - left + 1;
        }
        return len;
    }
};