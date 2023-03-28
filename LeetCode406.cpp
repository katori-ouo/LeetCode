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
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i++)
        {
            int cnt = people[i][1];
            res.insert(res.begin() + cnt, people[i]);
        }
        return res;
    }
};