#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int zeroCnt = 0;
        int slow = 0;
        for (int fast = slow; fast < nums.size(); fast++)
        {
            if (nums[fast] == 0)
            {
                zeroCnt++;
            }
            else
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        for (; slow < nums.size(); slow++)
        {
            nums[slow] = 0;
        }
    }
};