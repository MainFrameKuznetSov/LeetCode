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

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr)
        {
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return 1;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverse(slow->next);
        ListNode* fpart=head;
        ListNode* spart=newHead; 
        while(spart)
        {
            if(fpart->val!=spart->val)
            {
                reverse(newHead);
                return 0;
            }
            fpart=fpart->next;
            spart=spart->next;
        }
        reverse(newHead);
        return 1;
    }
};