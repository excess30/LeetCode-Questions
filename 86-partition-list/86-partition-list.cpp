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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* firstHalf = new ListNode(0);
        ListNode* secondHalf = new ListNode(0);
        ListNode* firstHalfPtr = firstHalf;
        ListNode* secondHalfPtr = secondHalf;
        while(head)
        {
            if(head->val<x)
            {
                firstHalf->next=head;
                firstHalf=firstHalf->next;
            }
            else
            {
                secondHalf->next=head;
                secondHalf=secondHalf->next;
            }
            head=head->next;
        }
        secondHalf->next=NULL;
        firstHalf->next=secondHalfPtr->next;
        return firstHalfPtr->next;
    }
};


