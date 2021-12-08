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

    private int sum;

    public int findTilt(TreeNode root) {
        if (root == null) {
            return 0;
        }
        sum = 0;
        helper(root);
        return sum;
    }

    private int helper(TreeNode root) {
        int left = 0;
        if (root.left != null) {
            left = helper(root.left);
        }
        int right = 0;
        if (root.right != null) {
            right = helper(root.right);
        }
        int curr = root.val;

        sum += Math.abs(left - right);
        return curr + left + right;
    }
}
