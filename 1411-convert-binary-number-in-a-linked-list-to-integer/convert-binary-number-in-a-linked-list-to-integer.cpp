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
    int getDecimalValue(ListNode* head) {
        string str="";
        ListNode* temp=head;
        while(temp)
        {
            str+=to_string(temp->val);
            temp=temp->next;
        }
        int n=str.size(),ind=0,ans=0;
        for(int i=n-1;i>=0;--i)
        {
            ans+=(str[i]-'0')<<ind;
            ++ind;
        }
        return ans;
    }
};