#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 合并重叠区间 */
class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        vector<int> path = intervals[0];
        int curEnd = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= curEnd)
            {
                curEnd = max(curEnd, intervals[i][1]);
                path[1] = curEnd;
            }
            else
            {
                res.push_back(path);
                path = intervals[i];
                curEnd = intervals[i][1];
            }
        }
        res.push_back(path);
        return res;
    }
};