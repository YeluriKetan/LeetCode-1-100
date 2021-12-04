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

    private static int superTarget;

    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return 0;
        }
        superTarget = targetSum;
        return superHelper(root);
    }

    private int helper(TreeNode curr, int targetSum) {
        int total = 0;
        if (targetSum - curr.val == 0) {
            total++;
        }
        if (curr.left != null) {
            total += helper(curr.left, targetSum - curr.val);
        }
        if (curr.right != null) {
            total += helper(curr.right, targetSum - curr.val);
        }
        return total;
    }

    private int superHelper(TreeNode curr) {
        int total = 0;
        if (superTarget - curr.val == 0) {
            total++;
        }
        if (curr.left != null) {
            total += helper(curr.left, superTarget - curr.val);
            total += superHelper(curr.left);
        }
        if (curr.right != null) {
            total += helper(curr.right, superTarget - curr.val);
            total += superHelper(curr.right);
        }
        return total;
    }
}
