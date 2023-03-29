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

    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int res = 1;
        int curEnd = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (curEnd >= points[i][0])
            {
                curEnd = min(curEnd, points[i][1]);
            }
            else
            {
                res++;
                curEnd = points[i][1];
            }
        }
        return res;
    }
};