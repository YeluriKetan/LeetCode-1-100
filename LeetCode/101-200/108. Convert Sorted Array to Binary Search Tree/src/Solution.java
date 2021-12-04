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

    private static int[] arr;

    public TreeNode sortedArrayToBST(int[] nums) {
        arr = nums;
        TreeNode root = new TreeNode();
        int index = arr.length / 2;
        root.val = arr[index];
        root.left = helper(0, index - 1);
        root.right = helper(index + 1, arr.length - 1);
        return root;
    }

    private TreeNode helper(int low, int high) {
        if (high < low) {
            return null;
        }
        TreeNode curr = new TreeNode();
        int index = low + (high - low) / 2;
        curr.val = arr[index];
        curr.left = helper(low, index - 1);
        curr.right = helper(index + 1, high);
        return curr;
    }
}
