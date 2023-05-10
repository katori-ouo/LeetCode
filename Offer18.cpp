struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};
class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *pre = dummyHead;
        ListNode *cur = head;
        while (cur != nullptr && cur->val != val)
        {
            pre = pre->next;
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            return dummyHead->next;
        }
        pre->next = cur->next;
        return dummyHead->next;
    }
};
