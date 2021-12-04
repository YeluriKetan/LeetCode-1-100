import java.util.PriorityQueue;

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
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode curr = head;
        int len = 0;
        while (curr != null){
            len++;
            curr = curr.next;
        }
        int forAll = len / k;
        int forFirstCount = len % k;
        ListNode[] list = new ListNode[k];
        curr = head;
        for (int i = 0; i < k; i++) {
            int count = forAll;
            if (forFirstCount > 0) {
                forFirstCount--;
                count++;
            }
            ListNode newNode = null;
            if (count != 0) {
                newNode = new ListNode(curr.val);
                curr = curr.next;
                ListNode currNd = newNode;
                for (int j = 0; j < count - 1; j++) {
                    currNd.next = new ListNode(curr.val);
                    curr = curr.next;
                    currNd = currNd.next;
                }
            }
            list[i] = newNode;

        }
        return list;
    }
}