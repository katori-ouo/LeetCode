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

/*
优先队列法
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
                que.push({node.ptr->next->val, node.ptr->next});
        }
        return dummyHead->next;
    }
};
*/
/*
分治合并
*/
class Solution
{
public:
    ListNode *merge2Lists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummyHead->next;
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l > r)
            return nullptr;
        if (l == r)
            return lists[l];
        int mid = l + (r - l) / 2;
        ListNode *leftRes = merge(lists, l, mid);
        ListNode *rightRes = merge(lists, mid + 1, r);
        return merge2Lists(leftRes, rightRes);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }
};