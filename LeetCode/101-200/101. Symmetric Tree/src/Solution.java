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
    public boolean isSymmetric(TreeNode root) {
        return helper(root.left, root.right);
    }

    private boolean helper(TreeNode curr, TreeNode other) {
        if (curr == null && other == null) {
            return true;
        }
        if (curr == null || other == null) {
            return false;
        }
        if (curr.val != other.val) {
            return false;
        }
        return helper(curr.left, other.right) && helper(curr.right, other.left);
    }
}
