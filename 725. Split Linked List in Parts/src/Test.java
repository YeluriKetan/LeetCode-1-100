import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        ListNode list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        System.out.println(Arrays.toString(sol.splitListToParts(list, 3)));
    }
}
