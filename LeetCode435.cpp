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
        int len = intervals.size();
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int cover = intervals[0][1];
        for (int i = 1; i < len; i++)
        {
            int from = intervals[i][0], to = intervals[i][1];
            if (from < cover)
            {
                cnt++;
                cover = min(to, cover);
            }
            else
            {
                cover = to;
            }
        }
        return cnt;
    }
};