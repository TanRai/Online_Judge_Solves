class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* ptr = head;
        vector<int> vec;
        while(ptr)
        {
            vec.push_back(ptr->val);
            ptr = ptr->next;
        }
        int res = 0;
        int size = vec.size();
        for(int i=0; i<size/2;i++)
        {
            res = max(res,vec[i]+vec[size-i-1]);
        }
        return res;
    }
};

//Space optimized

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(fast && fast->next)
        {
            cur = slow;
            fast = fast->next->next;
            slow = slow->next;
            cur->next = prev;
            prev = cur;
        }
        int res = 0;
        while(slow)
        {
            res = max(res,slow->val+prev->val);
            slow = slow->next;
            prev = prev->next;
        }
        return res;
    }
};