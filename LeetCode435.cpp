#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        int curEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= curEnd)
                curEnd = intervals[i][1];
            else
            {
                res++;
                curEnd = min(curEnd, intervals[i][1]);
            }
        }
        return res;
    }
};