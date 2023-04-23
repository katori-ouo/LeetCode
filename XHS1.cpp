#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string res = "";
    int len = s.size();
    int numr = 0, numd = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == ')')
        {
            numr++;
            while (numr > 0)
            {
                i--;
                if (s[i] == ')')
                    numr++;
                else if (s[i] == '(')
                    numr--;
            }
        }
        else if (s[i] == '<')
        {
            numd++;
        }
        else
        {
            if (numd == 0)
                res.push_back(s[i]);
            else
                numd--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
}