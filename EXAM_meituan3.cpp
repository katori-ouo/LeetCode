#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, T;
    cin >> n >> T;
    vector<bool> isConnected(n, false);
    vector<pair<int, int>> res;
    char c;
    int node;
    int left = 0, right = 0, temp;
    for (int idx = 0; idx < T; idx++)
    {
        cin >> c;
        cin >> node;
        if (c == 'L')
        {
            if (node > 1)
            {
                isConnected[node - 1] = true;
            }
        }
        else if (c == 'R')
        {
            if (node < n)
            {
                isConnected[node] = true;
            }
        }
        else if (c == 'Q')
        {
            left = 0;
            temp = node - 1;
            while (temp > 0 && isConnected[temp])
            {
                temp--;
                left++;
            }
            right = 0;
            temp = node;
            while (temp < n && isConnected[temp])
            {
                temp++;
                right++;
            }
            res.push_back({node - left, node + right});
        }
    }
    int len = res.size();
    for (int i = 0; i < len; i++)
    {
        cout << res[i].first << " " << res[i].second << '\n';
    }
}