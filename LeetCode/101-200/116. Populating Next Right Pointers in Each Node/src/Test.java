public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Node root = new Node(1, new Node(2, new Node(4), new Node(5), null), new Node(3, new Node(6) , new Node(7), null), null);
        sol.connect(root);
    }
}
