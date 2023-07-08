#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        int slow = 0, fast = 0;
        for (fast = slow + 1; fast < len; fast++)
        {
            if (nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};