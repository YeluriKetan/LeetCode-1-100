public class Test {
    public static void main(String[] args) {
        ListNode root = new ListNode(1, new ListNode(0, new ListNode(0)));
        Solution sol = new Solution();
        System.out.println(sol.isPalindrome(root));
    }
}
