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
    public int rob(TreeNode root) {
        Pair pair = helper(root);
        return Math.max(pair.incl, pair.excl);
    }

    private Pair helper(TreeNode curr) {
        if (curr == null) {
            return new Pair(0, 0);
        }
        Pair left = helper(curr.left);
        Pair right = helper(curr.right);
        return new Pair(left.excl + right.excl + curr.val, Math.max(left.incl, left.excl) + Math.max(right.incl, right.excl));
    }

    private class Pair {
        public int incl;
        public int excl;

        private Pair(int incl, int excl) {
            this.incl = incl;
            this.excl = excl;
        }
    }
}
