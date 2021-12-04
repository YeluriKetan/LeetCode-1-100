/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    private static int maxPath;

    public int diameterOfBinaryTree(TreeNode root) {
        maxPath = 0;
        height(root);
        return maxPath;
    }

    private int height(TreeNode curr) {
        if (curr == null) {
            return 0;
        }

        int leftHeight = height(curr.left);
        int rightHeight = height(curr.right);

        maxPath = Math.max(maxPath, leftHeight + rightHeight);

        return Math.max(leftHeight, rightHeight) + 1;
    }
}
