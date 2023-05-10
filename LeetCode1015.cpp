#include <unordered_map>
using namespace std;

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        // 偶数必不能整除
        if (k % 2 == 0)
            return -1;
        // 5的倍数必不能整除
        else if (k % 5 == 0)
            return -1;
        unordered_map<int, int> mp;
        int resid = 1 % k, len = 1;
        mp[len] = resid;
        while (resid != 0)
        {
            resid = (resid * 10 + 1) % k;
            len++;
            if (mp.count(resid))
                return -1;
            mp[resid] = len;
        }
        return len;
    }
};