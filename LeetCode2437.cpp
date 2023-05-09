#include <string>
using namespace std;

class Solution
{
public:
    int countTime(string time)
    {
        int res = 1;
        // 小时位
        if (time[0] == '?')
        {
            if (time[1] == '?')
            {
                res *= 24;
            }
            else if (time[1] < '4')
            {
                res *= 3;
            }
            else
            {
                res *= 2;
            }
        }
        else if ((time[0] == '0' || time[0] == '1') && time[1] == '?')
        {
            res *= 10;
        }
        else if (time[0] == '2' && time[1] == '?')
        {
            res *= 4;
        }
        // 分钟位
        if (time[3] == '?')
        {
            if (time[4] == '?')
            {
                res *= 60;
            }
            else
            {
                res *= 6;
            }
        }
        else if (time[3] != '?' && time[4] == '?')
        {
            res *= 10;
        }
        return res;
    }
};