import java.util.Stack;

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
    public void reorderList(ListNode head) {
        Stack<ListNode> stack = new Stack<>();
        ListNode curr = head;
        while (curr != null) {
            stack.add(curr);
            curr = curr.next;
        }
        curr = head;
        while (true) {
            ListNode insert = stack.pop();
            if (curr == insert) {
                curr.next = null;
                break;
            } else if (curr.next == insert) {
                insert.next = null;
                break;
            }
            insert.next = curr.next;
            curr.next = insert;
            curr = insert.next;
        }
    }
}
