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

    private ListNode sortedList;

    public ListNode insertionSortList(ListNode head) {
        sortedList = head;
        ListNode curr = head.next;
        sortedList.next = null;
        while (curr != null) {
            ListNode temp = curr;
            curr = curr.next;
            insert(temp);
        }
        return sortedList;
    }

    private void insert(ListNode curr) {
        if (curr.val < sortedList.val) {
            curr.next = sortedList;
            sortedList = curr;
            return;
        }
        ListNode currSort = sortedList;
        while (currSort.next != null && curr.val > currSort.next.val) {
            currSort = currSort.next;
        }
        curr.next = currSort.next;
        currSort.next = curr;
    }
}
