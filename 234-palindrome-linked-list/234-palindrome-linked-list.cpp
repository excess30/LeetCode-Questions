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
        ListNode* fast=head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head=prev;
        return head;
    }
    
    bool isPalindrome(ListNode* head)
    {
        ListNode* midd = findMid(head);
        ListNode* dummy = reverse(midd);
        ListNode*curr = head;
        while(curr && dummy)
        {
            if(curr->val!=dummy->val)
            {
                return false;
            }
            curr=curr->next;
            dummy=dummy->next;
        }
        return true;
    }
};