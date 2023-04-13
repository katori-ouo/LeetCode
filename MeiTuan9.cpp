#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    vector<string> ans;
    int n, m, a, b;
    while (cin >> n)
    {
        cin >> m >> a >> b;
        vector<int> weights(m, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> weights[i];
        }
        int minW = min(a, b), maxW = max(a, b);
        sort(weights.begin(), weights.end());
        if (weights[0] < minW || weights[m - 1] > maxW)
        {
            ans.push_back("NO");
        }
        else if (minW == weights[0] && maxW == weights[m - 1])
        {
            ans.push_back("YES");
        }
        else if (minW == weights[0] && maxW > weights[m - 1])
        {
            if (n > m)
                ans.push_back("YES");
            else
                ans.push_back("NO");
        }
        else if (minW < weights[0] && maxW == weights[m - 1])
        {
            if (n > m)
                ans.push_back("YES");
            else
                ans.push_back("NO");
        }
        else if (minW < weights[0] && maxW > weights[m - 1])
        {
            if (n - m >= 2)
                ans.push_back("YES");
            else
                ans.push_back("NO");
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}