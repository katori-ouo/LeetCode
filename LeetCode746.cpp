#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int dp0 = 0;
        int dp1 = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            int dpi = min(dp1 + cost[i - 1], dp0 + cost[i - 2]);
            dp0 = dp1;
            dp1 = dpi;
        }
        return dp1;
    }
};