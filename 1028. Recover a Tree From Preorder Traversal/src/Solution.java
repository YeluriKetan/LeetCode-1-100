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

    private class Pair {
        private int depth;
        private int val;

        private Pair(int depth, int val) {
            this.depth = depth;
            this.val = val;
        }

        private int getDepth() {
            return this.depth;
        }

        private int getVal() {
            return this.val;
        }
    }

    private static String src;
    private static int index;
    private static Pair pair;

    public TreeNode recoverFromPreorder(String S) {
        Solution.src = S;
        Solution.index = 0;
        TreeNode root = null;
        next();
        if (pair != null && pair.depth == 0) {
            root = new TreeNode(pair.val);
            next();
            helper(root, 0);
            return root;
        } else {
            return null;
        }
    }

    private void helper(TreeNode curr, int depth) {
        if (pair == null || pair.depth <= depth) {
            return ;
        } else {
            curr.left = new TreeNode(pair.val);
            next();
            helper(curr.left, depth + 1);
        }
        if (pair == null || pair.depth <= depth) {
            return ;
        } else {
            curr.right = new TreeNode(pair.val);
            next();
            helper(curr.right, depth + 1);
        }
    }

    private void next() {
        Solution.pair = this.split();
    }

    private Pair split() {
        if (index == src.length()) {
            return null;
        }
        int depth = 0;
        int val = 0;
        while (index < src.length()) {
            if (src.charAt(index) == '-') {
                depth++;
                index++;
            } else {
                break;
            }
        }
        while (index < src.length()) {
            if (src.charAt(index) > 47 && src.charAt(index) < 58) {
                val *= 10;
                val += src.charAt(index) - 48;
                index++;
            } else {
                break;
            }
        }
        return new Pair(depth, val);
    }
}