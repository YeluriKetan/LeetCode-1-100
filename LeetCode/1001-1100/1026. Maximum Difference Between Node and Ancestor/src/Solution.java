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
    public int maxAncestorDiff(TreeNode root) {
        return helper(root, root.val, root.val);
    }

    private int helper(TreeNode root, int min, int max) {
        int currMax = Math.max(Math.abs(root.val - min), Math.abs(root.val - max));
        if (root.left != null) {
            currMax = Math.max(currMax, helper(root.left, Math.min(min, root.val), Math.max(max, root.val)));
        }
        if (root.right != null) {
            currMax = Math.max(currMax, helper(root.right, Math.min(min, root.val), Math.max(max, root.val)));
        }
        return currMax;
    }
}
