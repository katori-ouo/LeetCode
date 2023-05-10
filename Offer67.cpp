#include <string>
using namespace std;
class Solution
{
public:
    int strToInt(string str)
    {
        int len = str.size();
        long long num = 0;
        int ans = 0;
        bool positive = true;
        // 丢弃开头空格
        int left = 0;
        while (str[left] == ' ')
            left++;
        // 判断第一个非空字符是否有效
        if (str[left] > '9' || str[left] < '0')
        {
            if (str[left] != '+' && str[left] != '-')
                return 0;
            else if (str[left] == '+')
            {
                positive = true;
                left++;
            }
            else
            {
                positive = false;
                left++;
            }
        }
        while (left < len && str[left] >= '0' && str[left] <= '9')
        {
            num *= 10;
            num += str[left] - '0';
            if (positive && num >= INT32_MAX)
                return INT32_MAX;
            else if (!positive && num + INT32_MIN >= 0)
                return INT32_MIN;
            left++;
        }
        if (positive)
            ans = (int)num;
        else
            ans = -num;
        return ans;
    }
};

int main()
{
    string s = "42";
    Solution solve;
    solve.strToInt(s);
}