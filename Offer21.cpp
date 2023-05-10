#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> res(len, 0);
        if (len == 0)
            return res;
        int left = 0, right = len - 1;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] % 2 == 1)
            {
                res[left] = nums[i];
                left++;
            }
            else
            {
                res[right] = nums[i];
                right--;
            }
        }
        return res;
    }
};