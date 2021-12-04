public class Test {
    public static void main(String[] args) {
        Node three = new Node();
        three.val = 3;
        Node two = new Node();
        two.val = 2;
        Node one = new Node();
        one.val = 1;
        two.prev = one;
        one.next = two;
        one.child = three;
        Solution sol = new Solution();
        Node ans = sol.flatten(one);
        System.out.println("done");
    }
}
