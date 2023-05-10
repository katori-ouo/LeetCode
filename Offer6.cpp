#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> nums;
        ListNode *ptr = head;
        while (ptr != nullptr)
        {
            nums.emplace_back(ptr->val);
            ptr = ptr->next;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};
