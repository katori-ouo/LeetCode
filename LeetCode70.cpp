#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int p = 1, q = 1;
        int ans = 1;
        if (n <= 1)
            return ans;
        for (int i = 1; i < n; i++)
        {
            ans = p + q;
            p = q;
            q = ans;
        }
        return ans;
    }
};