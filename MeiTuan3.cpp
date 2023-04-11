#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reForm(string &s)
{
    int len = s.size();
    string front, back;
    int cut = 0;
    while (s[cut] != '.' && cut < len)
    {
        cut++;
    }
    //* 整数部分
    front = s.substr(0, cut);
    int numofDH = (cut - 1) / 3;
    front.resize(cut + numofDH);
    int cnt = 3;
    for (int i = cut - 1, j = cut + numofDH - 1; i < j; i--, j--)
    {
        cnt--;
        front[j] = front[i];
        if (cnt == 0)
        {
            j--;
            front[j] = ',';
            cnt = 3;
        }
    }
    //* 小数部分
    if (len == cut)
        back = "00";
    else if (len - cut - 1 == 1)
        back = s.substr(cut + 1, 1) + "0";
    else
        back = s.substr(cut + 1, 2);
    return front + "." + back;
}
int main()
{
    string s;
    vector<string> ans;
    while (cin >> s)
    {
        if (s[0] == '-')
        {
            string temp = s.substr(1, s.size() - 1);
            temp = "($" + reForm(temp) + ")";
            ans.push_back(temp);
        }
        else
        {
            string temp = "$";
            temp += reForm(s);
            ans.push_back(temp);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}