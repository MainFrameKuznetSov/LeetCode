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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        ListNode temp(0,head);
        ListNode* prev=&temp,*tmp=NULL;
        for(ListNode* curr=head;curr;curr=curr->next,delete tmp)
        {
            if(st.count(curr->val))
            { 
                prev->next=curr->next;
                tmp=curr;
            }
            else
            {
                prev=prev->next;
                tmp=NULL;
            }
        }
        return temp.next;
    }
};