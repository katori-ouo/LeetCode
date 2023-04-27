#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(string &s1, string &s2)
{
    if (s1[0] == s2[0])
    {
        return s1.size() > s2.size();
    }
    return s1[0] < s2[0];
}

// 根据字母组合成答案
string genS(vector<char> &temp)
{
    string res = "";
    int len = temp.size();
    sort(temp.begin(), temp.end());
    for (int i = 0; i < len; i++)
    {
        res += temp[i] - 32;
        res += temp[i];
    }
    return res;
}

// 找到s中的大小写字符c
vector<int> findC(string &s, char c, vector<bool> &canUse, int idx)
{
    vector<int> res = {-1, -1};
    int len = s.size();
    while ((res[0] == -1 || res[1] == -1) && idx < len)
    {
        if (canUse[idx])
        {
            if (res[0] == -1 && s[idx] == c - 32)
                res[0] = idx;
            else if (res[1] == -1 && s[idx] == c)
                res[1] = idx;
        }
        idx++;
    }
    return res;
}

vector<char> getPy(string &s, vector<bool> &canUse, int idx, vector<int> &recId)
{
    vector<char> Py;
    char left, right;
    if (s[idx] >= 'A' && s[idx] <= 'Z')
    {
        left = s[idx] + 32, right = s[idx] + 32 + 1;
    }
    else
    {
        left = s[idx];
        right = s[idx] + 1;
    }
    vector<int> pos;
    pos = findC(s, left, canUse, idx);
    if (pos[0] == -1 || pos[1] == -1)
        return Py;
    else
    {
        while (pos[0] != -1 && pos[1] != -1)
        {
            Py.emplace_back(s[pos[1]]);
            recId[pos[0]] = 1;
            recId[pos[1]] = 1;
            left--;
            pos = findC(s, left, canUse, idx);
        }
    }
    pos = findC(s, right, canUse, idx);
    if (pos[0] == -1 || pos[1] == -1)
        return Py;
    else
    {
        while (pos[0] != -1 && pos[1] != -1)
        {
            Py.emplace_back(s[pos[1]]);
            recId[pos[0]] = 1;
            recId[pos[1]] = 1;
            right++;
            pos = findC(s, right, canUse, idx);
        }
    }
    return Py;
}

void backtracking(vector<string> &res, string &s, vector<bool> &canUse)
{
    int len = s.size();
    vector<int> recIdx(len, 0);
    vector<char> ans;
    int maxLen = 0;
    for (int i = 0; i < len; i++)
    {
        vector<int> temp(len, 0);
        vector<char> tempC = getPy(s, canUse, i, temp);
        int subLen = tempC.size();
        if (subLen > maxLen)
        {
            maxLen = subLen;
            recIdx = temp;
            ans = tempC;
        }
    }
    if (maxLen == 0)
        return;
    res.push_back(genS(ans));
    for (int i = 0; i < len; i++)
    {
        if (recIdx[i] == 1)
        {
            canUse[i] = false;
        }
    }
    backtracking(res, s, canUse);
    return;
}

int main()
{
    string s;
    cin >> s;
    // 只保留字母
    int len = s.size();
    int left = 0, right = 0;
    for (; right < len; right++)
    {
        if ((s[right] >= 'A' && s[right] <= 'Z') || (s[right] >= 'a' && s[right] <= 'z'))
        {
            s[left] = s[right];
            left++;
        }
    }
    s.resize(left);
    len = left;
    vector<bool> canUse(len, true);
    vector<string> res;
    backtracking(res, s, canUse);
    sort(res.begin(), res.end(), cmp);
    int numRes = res.size();
    if (numRes == 0)
    {
        cout << "Not Found" << '\n';
    }
    else
    {
        for (int i = 0; i < numRes; i++)
        {
            cout << res[i] << '\n';
        }
    }
    return 0;
}