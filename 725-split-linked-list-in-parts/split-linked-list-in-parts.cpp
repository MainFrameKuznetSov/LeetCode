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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k);
        int size=0;
        ListNode* curr=head;
        while(curr) 
        {
            ++size;
            curr=curr->next;
        }
        int split=size/k,rem=size%k;
        curr=head;
        ListNode* prev=curr;
        for(int i=0;i<k;++i) 
        {
            ListNode* newPart=curr;
            int currSize=split;
            if(rem>0) 
            {
                --rem;
                ++currSize;
            }
            int j=0;
            while(j<currSize) 
            {
                prev=curr;
                if(curr)
                    curr=curr->next;
                j++;
            }
            if(prev)
                prev->next=NULL;
            ans[i]=newPart;
        }
        return ans;
    }
};