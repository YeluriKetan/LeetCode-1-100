public class Test {
    public static void main(String[] args) {
        ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
        ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(6)));
        Solution sol = new Solution();
        ListNode ans = sol.addTwoNumbers(l1, l2);
        while (ans != null) {
            System.out.print(ans.val + ", ");
            ans = ans.next;
        }
    }
}
