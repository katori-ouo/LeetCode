#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    int cnt = 0;
    for (int idx = 0; idx < n; idx++)
    {
        cin >> matrix[idx];
    }
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = 0; j <= m - 2; j++)
        {
            // 0y,1o,2u
            vector<int> chars(3, 0);
            for (int p = i; p <= i + 1; p++)
            {
                for (int q = j; q <= j + 1; q++)
                {
                    if (matrix[p][q] == 'y')
                        chars[0]++;
                    else if (matrix[p][q] == 'o')
                        chars[1]++;
                    else if (matrix[p][q] == 'u')
                        chars[2]++;
                }
            }
            if (chars[0] > 0 && chars[1] > 0 && chars[2] > 0)
                cnt++;
        }
    }
    cout << cnt << '\n';
}