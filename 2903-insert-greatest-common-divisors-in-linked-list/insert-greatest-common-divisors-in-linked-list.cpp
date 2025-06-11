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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head)   
            return NULL;
        ListNode* curr=head;
        while(curr && curr->next)
        {
            int A=curr->val,B=curr->next->val;
            int gcd=__gcd(A,B);
            //cout<<A<<" "<<B<<" "<<gcd<<"\n";
            ListNode* temp=new ListNode(gcd);
            temp->next=curr->next;
            curr->next=temp;
            curr=curr->next->next;            
        }
        return head;
    }
};