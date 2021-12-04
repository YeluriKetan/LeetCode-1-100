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
    static int count = 0;
    public TreeNode bstToGst(TreeNode root) {
        count = 0;
        if (root == null) {
            return null;
        }
        if (root.right != null) {
            bstToGstHelper(root.right);
        }
        root.val += count;
        count = root.val;
        if (root.left != null) {
            bstToGstHelper(root.left);
        }
        return root;
    }

    public void bstToGstHelper(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.right != null) {
            bstToGstHelper(root.right);
        }
        root.val += count;
        count = root.val;
        if (root.left != null) {
            bstToGstHelper(root.left);
        }
    }
}