#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool find = false;
    int idx = 0;
    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (; idx < n; idx++)
        {
            if (s[idx] == t[i])
            {
                idx++;
                sum += idx;
                cnt++;
                break;
            }
        }
    }
    if (cnt != m)
    {
        cout << "No" << '\n';
    }
    else
    {
        cout << "Yes" << '\n';
        cout << sum << '\n';
    }
}