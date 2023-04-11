#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int idx1 = (k - 1) / n;
    int idx2 = (k - 1) % n;
    cout << "(" << nums[idx1] << "," << nums[idx2] << ")" << endl;
}