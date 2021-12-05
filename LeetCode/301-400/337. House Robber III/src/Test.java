public class Test {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(4,
                new TreeNode(1, new TreeNode(2, new TreeNode(3), null), null),
                null);
        Solution sol = new Solution();
        System.out.println("Expected: 7, Actual: " + sol.rob(root));
    }
}
