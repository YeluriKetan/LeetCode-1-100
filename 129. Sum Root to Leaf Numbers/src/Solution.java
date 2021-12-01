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

    public int sumNumbers(TreeNode root) {
        total = 0;
        helper(root, 0);
        return total;
    }

    private void helper(TreeNode curr, int currTotal) {
        currTotal *= 10;
        currTotal += curr.val;

        if (curr.left == null && curr.right == null) {
            total += currTotal;
            return;
        }

        if (curr.left != null) {
            helper(curr.left, currTotal);
        }
        if (curr.right != null) {
            helper(curr.right, currTotal);
        }
    }
}
