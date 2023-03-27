#include <iostream>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    struct valNode
    {
        int val;
        ListNode *ptr;
        bool operator<(const valNode &rhs) const
        {
            return val > rhs.val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<valNode> que;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                que.push({lists[i]->val, lists[i]});
            }
        }
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        while (!que.empty())
        {
            valNode node = que.top();
            que.pop();
            cur->next = node.ptr;
            cur = cur->next;
            if (node.ptr->next)
            {
                que.push({node.ptr->next->val, node.ptr->next});
            }
        }
        return dummyHead->next;
    }
};