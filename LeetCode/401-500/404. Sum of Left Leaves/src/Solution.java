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

    private static int total;

    public int sumOfLeftLeaves(TreeNode root) {
        total = 0;
        helper(root);
        return total;
    }

    private void helper(TreeNode curr) {
        if (curr.left != null) {
            if (curr.left.left == null && curr.left.right == null) {
                total += curr.left.val;
            } else {
                helper(curr.left);
            }
        }

        if (curr.right != null) {
            helper(curr.right);
        }
    }
}
