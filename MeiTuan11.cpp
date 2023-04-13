#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, n;
    int maxSum = INT32_MIN, minSum = INT32_MIN;
    int sum = 0;
    int val;
    cin >> t;
    vector<int> ans(t, 0);
    for (int idx = 0; idx < t; idx++)
    {
        cin >> n;
        vector<int> dpMax(n, 0);
        vector<int> dpMin(n, 0);
        cin >> val;
        dpMax[0] = val;
        dpMin[0] = val;
        maxSum = val;
        minSum = val;
        sum = val;
        for (int i = 1; i < n; i++)
        {
            cin >> val;
            dpMax[i] = max(dpMax[i - 1] + val, val);
            maxSum = max(dpMax[i], maxSum);
            dpMin[i] = min(dpMin[i - 1] + val, val);
            minSum = min(dpMin[i], minSum);
            sum += val;
        }
        ans[idx] = max(maxSum, sum - minSum);
    }
    for (int i = 0; i < t; i++)
    {
        cout << ans[i] << '\n';
    }
}