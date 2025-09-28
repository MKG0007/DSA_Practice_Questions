/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode a = new ListNode(0);
        ListNode ans = a;
        ListNode h1 = list1;
        ListNode h2 = list2;

        while(h1 != null && h2 != null){
            ListNode newNode = new ListNode();
            if(h1.val<=h2.val) {
                newNode.val = h1.val;
                ans.next = newNode;
                h1 = h1.next;
            }
            else {
                newNode.val = h2.val;
                ans.next = newNode;
                h2 = h2.next;
            }
                ans = ans.next;
        }

        while(h1 != null){
                        ListNode newNode = new ListNode();
                newNode.val = h1.val;
                ans.next = newNode;
            h1 = h1.next;
                ans = ans.next;

        }
            while(h2 != null){
                            ListNode newNode = new ListNode();
                newNode.val = h2.val;
                ans.next = newNode;
                ans = ans.next;
            h2 = h2.next;

        }


        return a.next;
    }
}