/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode curr = head;
        while (true) {
            if (curr == null) {
                return false;
            }
            if (curr.val == 100001) {
                return true;
            } else {
                curr.val = 100001;
                curr = curr.next;
            }
        }
    }
}
