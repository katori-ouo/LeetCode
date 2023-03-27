#include <iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int p = 0, q = 1;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = p + q;
            p = q;
            q = ans;
        }
        return ans;
    }
};