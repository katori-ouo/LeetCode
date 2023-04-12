#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, i;
    long long k, t;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    k--;
    for (i = 0; i < n; i += t)
    {
        for (t = 1; nums[i] == nums[i + t]; t++)
            ;
        if (t * n > k)
            break;
        k -= t * n;
    }
    cout << "(" << nums[i] << "," << nums[k / t] << ")\n";
}