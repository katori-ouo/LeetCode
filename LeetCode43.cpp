#include <iostream>
#include <string>
#include <vector>
using namespace std;

string addString(string num1, string num2)
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

string myMultiply(string num1, int num2)
{
    if (num1 == "0" || num2 == "0")
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
        res = addString(res, temp);
    }
    return res;
}

string multiply(string num1, string num2)
{
    string res = "";
    for (int i = 0; i < num2.size(); i++)
    {
        int num = num2[i] - '0';
        string temp = myMultiply(num1, num);
        res.push_back('0');
        res = addString(res, temp);
    }
    return res;
}

int main()
{
    string num1 = "498828660196";
    string num2 = "840477629533";
    string res = multiply(num1, num2);
    cout << res;
    return 0;
}