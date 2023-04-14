#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* 贪心算法 最大的各位递增的数字 */
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string num = to_string(n);
        int idx = num.size();
        for (int i = num.size() - 1; i > 0; i--)
        {
            if (num[i - 1] > num[i])
            {
                idx = i;
                num[i - 1]--;
            }
        }
        for (int i = idx; i < num.size(); i++)
        {
            num[i] = '9';
        }
        return stoi(num);
    }
};