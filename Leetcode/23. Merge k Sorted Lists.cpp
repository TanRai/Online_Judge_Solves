/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 ListNode* merge(ListNode* left,ListNode* right)
 {
    ListNode* head = new ListNode();
    ListNode* ptr = head;
    while(left!=nullptr && right!=nullptr)
    {
        if(left->val<=right->val)
        {
            ptr->next = new ListNode(left->val);
            left = left->next;
        }
        else
        {
            ptr->next = new ListNode(right->val);
            right = right->next;
        }
        ptr = ptr->next;
    }
    ptr->next = left ? left : right;
    head = head->next;
    return head;
 }

ListNode* mergeSort(vector<ListNode*>& lists,int s,int e)
{
    if(e==s)
        return lists[s];
    int m = (s+e)/2;
    ListNode* left = mergeSort(lists,s,m);
    ListNode* right = mergeSort(lists,m+1,e);

    ListNode* res = merge(left,right);

    return res;
}



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        return mergeSort(lists,0,lists.size()-1);
    }
};