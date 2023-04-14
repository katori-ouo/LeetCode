#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 贪心算法 分发饼干 */
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int idx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (idx < g.size() && g[idx] <= s[i])
                idx++;
        }
        return idx;
    }
};