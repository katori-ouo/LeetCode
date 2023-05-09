#include <string>
using namespace std;
class Solution
{
public:
    /**
     * @brief 判断字符串是否为整数
     *
     * @param num 完整字符串
     * @param left 起点
     * @param right 终点
     * @return true 是整数
     * @return false 不是整数
     */
    bool isInt(string &num, int left, int right)
    {
        if (num[left] == '+' || num[left] == '-')
            left++;
        if (right < left)
            return false;
        for (int i = left; i <= right; i++)
        {
            if (num[i] > '9' || num[i] < '0')
                return false;
        }
        return true;
    }

    /**
     * @brief 判断字符串是否是小数
     *
     * @param num 字符串
     * @param left 起点
     * @param right 终点
     * @return true 是小数
     * @return false 不是小数
     */
    bool isFloat(string &num, int left, int right)
    {
        if (num[left] == '+' || num[left] == '-')
            left++;
        if (right < left)
            return false;
        int dotCnt = 0;
        for (int i = left; i <= right; i++)
        {
            if (num[i] == '.')
            {
                dotCnt++;
                if (dotCnt > 1)
                    return false;
                if (i == left && i == right)
                    return false;
            }
            else if (num[i] > '9' || num[i] < '0')
                return false;
        }
        if (dotCnt == 0)
            return false;
        return true;
    }

    bool isNumber(string s)
    {
        int lens = s.size();
        int eIdx = -1;
        int preSpace = 0, endSpace = 0;
        int numCnt = 0;
        for (int i = 0; i < lens; i++)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                if (eIdx != -1)
                    return false;
                else
                {
                    eIdx = i;
                }
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
                return false;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                return false;
            else if (s[i] == ' ')
            {
                if (numCnt == 0)
                    preSpace++;
                else
                    endSpace++;
            }
            else
            {
                numCnt++;
            }
        }
        if (eIdx == -1)
        {
            bool res1 = isInt(s, preSpace, lens - endSpace - 1);
            bool res2 = isFloat(s, preSpace, lens - endSpace - 1);
            return (res1 || res2);
        }
        bool res1 = isInt(s, preSpace, eIdx - 1);
        bool res2 = isFloat(s, preSpace, eIdx - 1);
        bool res3 = isInt(s, eIdx + 1, lens - endSpace - 1);
        return ((res1 || res2) && res3);
    }
};

int main()
{
    string s = "  .1   ";
    Solution solve;
    solve.isNumber(s);
    return 0;
}