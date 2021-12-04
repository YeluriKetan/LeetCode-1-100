public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        TreeNode root = new TreeNode(1, null, new TreeNode(2, null, new TreeNode(3, null,
                new TreeNode(4, null, new TreeNode(5)))));
        System.out.println(sol.pathSum(root, 3));
    }
}
