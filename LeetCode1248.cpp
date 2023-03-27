#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> mp;
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        // vector<int> preOdd(nums.size() + 1, 0);
        mp[0] = 1;
        int res = 0;
        int oddCnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 1)
            {
                oddCnt++;
            }
            mp[oddCnt]++;
            if (mp.count(oddCnt - k))
            {
                res += mp[oddCnt - k];
            }
        }
        return res;
    }
};