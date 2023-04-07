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
        int len = points.size();
        int cover = points[0][1];
        int cnt = 1;
        for (int i = 1; i < len; i++)
        {
            int from = points[i][0], to = points[i][1];
            if (from <= cover)
            {
                cover = min(cover, to);
            }
            else
            {
                cnt++;
                cover = to;
            }
        }
        return cnt;
    }
};