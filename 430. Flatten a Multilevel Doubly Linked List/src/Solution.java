/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    public Node flatten(Node head) {
        if (head == null) {
            return null;
        }

        Node curr = head;
        Node currNext;
        while (curr != null) {
            currNext = curr.next;
            curr = helper(curr);
            curr.next = currNext;
            if (currNext != null) {
                currNext.prev = curr;
            }
            curr = curr.next;
        }
        return head;
    }

    private Node helper(Node head) {
        if (head.child == null) {
            return head;
        }
        Node curr = head;
        Node childCurr = head.child;
        head.child = null;
        while (childCurr != null) {
            curr.next = childCurr;
            childCurr.prev = curr;
            childCurr = childCurr.next;
            curr = helper(curr.next);
        }
        return curr;
    }
}
