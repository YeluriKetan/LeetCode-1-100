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
    public boolean isPalindrome(ListNode head) {
        int len = 0;
        ListNode curr = head;
        while (curr != null) {
            len++;
            curr = curr.next;
        }
        if (len == 1) {
            return true;
        }
        curr = head;
        ListNode temp;
        ListNode other = head.next;
        curr.next = null;
        for (int i = 0; i < (len - 2) / 2; i++) {
            temp = other.next;
            other.next = curr;
            curr = other;
            other = temp;
        }
        if (len % 2 == 1) {
            other = other.next;
        }
        while (curr != null) {
            if (curr.val != other.val) {
                return false;
            }
            curr = curr.next;
            other = other.next;
        }
        return true;
    }
}
