class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};