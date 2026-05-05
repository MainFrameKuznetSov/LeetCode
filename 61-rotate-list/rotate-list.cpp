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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !(head->next))
            return head;
        int rot=1;
        ListNode* last=head;
        while(last->next)
        {
            last=last->next;
            ++rot;
        }
        k=k%rot;
        if(k==0)
            return head;
        last->next=head;

        int cnt=rot-k;
        ListNode* newLast=head;
        for(int i=1;i<cnt;++i)
            newLast=newLast->next;
        ListNode* ans=newLast->next;
        newLast->next=NULL;

        return ans;

    }
};