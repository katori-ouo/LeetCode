#include <vector>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = x;
        int ans = 0;
        while (left <= right)
        {
            ans = left + (right - left) / 2;
            if ((long long)ans * ans == x)
                return ans;
            else if ((long long)ans * ans > x)
            {
                right = ans - 1;
            }
            else if ((long long)ans * ans < x)
            {
                left = ans + 1;
            }
        }
        return right;
    }
};