#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += abs(nums[i] - (i + 1));
    }
    cout << cnt << '\n';
}