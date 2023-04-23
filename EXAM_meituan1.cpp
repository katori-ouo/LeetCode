#include <iostream>
#include <vector>
#include <string>
using namespace std;

int process(string &s, string &t)
{
    int lens = s.size(), lent = t.size();
    int cnt = 0;
    if (lens >= lent)
    {
        cnt += lens - lent;
        for (int i = 0; i < lent; i++)
        {
            if (s[i] != t[i])
                cnt++;
        }
    }
    else if (lens < lent)
    {
        // cnt += lent - lens;
        for (int i = 0; i < lens; i++)
        {
            if (s[i] != t[i])
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    int c;
    cin >> c;
    string s, t;
    vector<int> ans(c, 0);
    for (int i = 0; i < c; i++)
    {
        cin >> s >> t;
        ans[i] = process(s, t);
    }
    for (int i = 0; i < c; i++)
    {
        cout << ans[i] << '\n';
    }
}