#include <iostream>
#include <vector>
using namespace std;

int process(int n, int a, int b)
{
    int res = INT32_MIN, numa, numb;
    for (int i = 1; i <= n - 1; i++)
    {
        int j = n - i;
        numa = a / i;
        numb = b / j;
        res = max(res, min(numa, numb));
    }
    if (b / n > 0)
        res = max(res, b / n);
    if (a / n > 0)
        res = max(res, a / n);
    return res;
}

int main()
{
    int k;
    cin >> k;
    int n, a, b;
    vector<int> ans(k, 0);
    for (int i = 0; i < k; i++)
    {
        cin >> n >> a >> b;
        ans[i] = process(n, a, b);
    }
    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << '\n';
    }
}