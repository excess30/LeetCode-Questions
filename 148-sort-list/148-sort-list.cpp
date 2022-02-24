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
class Solution {
public:
    
    ListNode* findMid(ListNode* head)
    {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* mergeLists(ListNode* first, ListNode* second)
    {
        if(first==NULL)
        {
            return second;
        }
        if(second==NULL)
        {
            return first;
        }
        ListNode* third;
        if(first->val<second->val)
        {
            third=first;
            third->next = mergeLists(first->next,second);
        }
        else
        {
            third=second;
            third->next = mergeLists(first,second->next);
        }
        return third;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* mid = findMid(head);
        ListNode* second = sortList(mid->next);
        mid->next=NULL;
        ListNode* first = sortList(head);
        return mergeLists(first,second);
    }
};

