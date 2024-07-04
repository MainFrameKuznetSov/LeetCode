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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* change=head->next;
        ListNode* postSum=change;
        while(postSum!=NULL)
        {
            int temp=0;
            while(postSum->val!=0)
            {
                temp+=postSum->val;
                postSum=postSum->next;
            }
            change->val=temp;
            postSum=postSum->next;
            change->next=postSum;
            change=change->next;
        }
        return head->next;
    }
};