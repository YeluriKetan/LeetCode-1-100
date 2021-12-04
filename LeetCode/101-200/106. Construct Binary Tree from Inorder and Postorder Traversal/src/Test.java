public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] inorder = {9,3,15,20,7};
        int[] postorder = {9,15,7,20,3};
        TreeNode ans = sol.buildTree(inorder, postorder);
        System.out.println("Done");
    }
}
