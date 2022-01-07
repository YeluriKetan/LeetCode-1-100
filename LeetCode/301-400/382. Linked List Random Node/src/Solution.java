import java.util.Random;

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

    private int[] arr;
    private Random rand;

    public Solution(ListNode head) {
        int length = 0;
        ListNode curr = head;
        while (curr != null) {
            length++;
            curr = curr.next;
        }
        arr = new int[length];
        curr = head;
        for (int i = 0; i < length; i++) {
            arr[i] = curr.val;
            curr = curr.next;
        }
        rand = new Random();
    }

    public int getRandom() {
        return arr[rand.nextInt(arr.length)];
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
