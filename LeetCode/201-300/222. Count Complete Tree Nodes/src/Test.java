public class Test {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
        Solution sol = new Solution();
        System.out.println(sol.countNodes(root));
    }
}
