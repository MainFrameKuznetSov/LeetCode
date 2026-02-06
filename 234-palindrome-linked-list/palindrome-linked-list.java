/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    ListNode reverse(ListNode head)
    {
        if(head==null || head.next==null)
            return head;
        ListNode prev=null;
        ListNode curr=head;
        while(curr!=null)
        {
            ListNode nextNode=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }

    public boolean isPalindrome(ListNode head) {
        if(head==null || head.next==null)
            return true;
        ListNode slow=head,fast=head;
        while(fast.next!=null && fast.next.next!=null)//O(n/2)
        {
            slow=slow.next;
            fast=fast.next.next;
        }
        ListNode newHead=reverse(slow.next);//O(n/2)
        // reverse(newHead);
        ListNode left=head,right=newHead;
        while(right!=null)//O(n/2)
        {
            if(right.val!=left.val)
            {
                reverse(newHead);
                return false;
            }
            left=left.next;
            right=right.next;
        }
        reverse(newHead);//O(n/2)
        return true;
    }
}