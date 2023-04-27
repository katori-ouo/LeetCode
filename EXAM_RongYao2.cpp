#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> zhao(n, 0);
    vector<int> qin(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> qin[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> zhao[i];
    }
    sort(zhao.begin(), zhao.end());
    sort(qin.begin(), qin.end());
    int idx = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        while (idx < n && zhao[idx] <= qin[i])
        {
            idx++;
        }
        if (idx == n)
            break;
        else
        {
            idx++;
            cnt++;
        }
    }
    if (cnt > n / 2)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
    return 0;
}