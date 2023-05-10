#include <string>
#include <iostream>
#include <vector>
using namespace std;

/* 比较num1是否大于num2 */
bool cmp(string num1, string num2)
{
    if (num1.size() > num2.size())
    {
        string temp(num1.size() - num2.size(), '0');
        num2 = temp + num2;
    }
    else if (num1.size() < num2.size())
    {
        string temp(num2.size() - num1.size(), '0');
        num1 = temp + num1;
    }
    int len = num1.size();
    for (int i = 0; i < len; i++)
    {
        if (num1[i] > num2[i])
            return true;
        else if (num1[i] < num2[i])
            return false;
    }
    return true;
}

/* 比较num1是否大于num2, 带符号位 */
bool cmp2(string num1, string num2)
{
    char s1 = num1[0], s2 = num2[0];
    num1 = num1.substr(1, num1.size() - 1);
    num2 = num2.substr(1, num2.size() - 1);
    if (s1 == '+' && s2 == '-')
        return true;
    else if (s1 == '-' && s2 == '+')
        return false;
    else if (s1 == '+' && s2 == '+')
        return cmp(num1, num2);
    else
        return !cmp(num1, num2);
}

/* 两个字符串表示的数字相加 */
string plusString(string num1, string num2)
{
    if (num1.size() > num2.size())
    {
        string temp(num1.size() - num2.size(), '0');
        num2 = temp + num2;
    }
    else if (num1.size() < num2.size())
    {
        string temp(num2.size() - num1.size(), '0');
        num1 = temp + num1;
    }
    vector<int> ans(num1.size() + 1, 0);
    int x = 0, y = 0, res = 0, idx = 0;
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        x = num1[i] - '0';
        y = num2[i] - '0';
        res = (x + y + idx) % 10;
        idx = (x + y + idx) / 10;
        ans[i + 1] = res;
    }
    ans[0] = idx;
    string result = (ans[0] == 0) ? "" : to_string(ans[0]);
    for (int i = 1; i < ans.size(); i++)
    {
        result += to_string(ans[i]);
    }
    return result;
}

/* num1-num2, where num1 > num2 */
string myMinus(string num1, string num2)
{
    vector<int> ans(num1.size() + 1, 0);
    int x = 0, y = 0, res = 0, idx = 0;
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        x = num1[i] - '0';
        y = num2[i] - '0';
        x -= idx;
        if (x >= y)
        {
            res = x - y;
            idx = 0;
            ans[i + 1] = res;
        }
        else
        {
            res = x + 10 - y;
            idx = 1;
            ans[i + 1] = res;
        }
    }
    string result = "";
    for (int i = 1; i < ans.size(); i++)
    {
        result += to_string(ans[i]);
    }
    return result;
}

/* 两个字符串表示的数字相减 */
string minusString(string num1, string num2)
{
    if (num1.size() > num2.size())
    {
        string temp(num1.size() - num2.size(), '0');
        num2 = temp + num2;
    }
    else if (num1.size() < num2.size())
    {
        string temp(num2.size() - num1.size(), '0');
        num1 = temp + num1;
    }
    bool num1Bigger = cmp(num1, num2);
    string res = num1Bigger ? "+" : "-";
    if (num1Bigger)
        res += myMinus(num1, num2);
    else
        res += myMinus(num2, num1);
    return res;
}

/* 字符串表示的数字和一个个位数数相乘 */
string myMultiply(string num1, int num2)
{
    if (num1 == "0" || num2 == 0)
        return "0";
    string res = "";
    int x = 0, y = 0;
    string temp;
    for (int i = 0; i < num1.size(); i++)
    {
        x = num1[i] - '0';
        y = x * num2;
        temp = to_string(y);
        res.push_back('0');
        res = plusString(res, temp);
    }
    return res;
}

/* 两个字符串表示的数字相乘 */
string mulString(string num1, string num2)
{
    string res = "";
    for (int i = 0; i < num2.size(); i++)
    {
        int num = num2[i] - '0';
        string temp = myMultiply(num1, num);
        res.push_back('0');
        res = plusString(res, temp);
    }
    return res;
}

/* 判断一个字符串是否每一位都相等 */
bool isValid(string &num)
{
    char c = num[0];
    int len = num.size();
    for (int i = 1; i < len; i++)
    {
        if (num[i] != c)
            return false;
    }
    return true;
}

/* 取出所有长度在3-12之间的子字符串 */
vector<string> getS(string &num)
{
    int len = num.size();
    vector<string> res;
    string temp;
    for (int i = 0; i < len; i++)
    {
        for (int n = 3; n <= 12 && i + n <= len; n++)
        {
            temp = num.substr(i, n);
            res.push_back(temp);
        }
    }
    return res;
}

int main()
{
    string M, N;
    char k;
    cin >> M >> N >> k;
    vector<string> nums = getS(M);
    int n = nums.size();
    string temp, res = "-1";
    string resNum = "";
    if (k == '+')
    {
        for (int idx = 0; idx < n; idx++)
        {
            temp = plusString(nums[idx], N);
            if (isValid(temp))
            {
                if (res == "-1")
                {
                    res = nums[idx];
                    resNum = temp;
                }
                else if (cmp(temp, resNum))
                {
                    res = nums[idx];
                    resNum = temp;
                }
            }
        }
    }
    else if (k == '*')
    {
        for (int idx = 0; idx < n; idx++)
        {
            temp = mulString(nums[idx], N);
            if (isValid(temp))
            {
                if (res == "-1")
                {
                    res = nums[idx];
                    resNum = temp;
                }
                else if (cmp(temp, resNum))
                {
                    res = nums[idx];
                    resNum = temp;
                }
            }
        }
    }
    else if (k == '-')
    {
        for (int idx = 0; idx < n; idx++)
        {
            temp = minusString(nums[idx], N);
            string temp2 = temp.substr(1, temp.size() - 1);
            if (isValid(temp2))
            {
                if (res == "-1")
                {
                    res = nums[idx];
                    resNum = temp;
                }
                else if (cmp2(temp, resNum))
                {
                    res = nums[idx];
                    resNum = temp;
                }
            }
        }
    }
    cout << res << endl;
}