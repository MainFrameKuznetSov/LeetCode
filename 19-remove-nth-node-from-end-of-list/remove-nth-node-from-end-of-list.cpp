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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        ListNode* curr=head;
        int size=0;
        while(curr)
        {
            ++size;
            curr=curr->next;
        }
        int k=size-n+1,ind=0;
        if(k==1)
        {
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        curr=head;
        while(curr)
        {
            ++ind;
            if(ind==k-1)
            {
                ListNode* temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
                return head;
            }
            curr=curr->next;
        }
        return head;
    }
};