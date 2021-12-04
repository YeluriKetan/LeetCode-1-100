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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }

        if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } else if (key > root.val) {
            root.right = deleteNode(root.right, key);
        } else {
            return delete(root);
        }

        return root;
    }

    private TreeNode delete(TreeNode root) {
        if (root.left == null && root.right == null) {
            return null;
        }

        if (root.left == null) {
            return root.right;
        }

        if (root.right == null) {
            return root.left;
        }

        if (root.left.right == null) {
            root.left.right = root.right;
            return root.left;
        }

        TreeNode prev = root;
        TreeNode curr = root.left;
        while (curr.right != null) {
            prev = curr;
            curr = curr.right;
        }
        root.val = curr.val;
        prev.right = curr.left;
        return root;
    }
}
