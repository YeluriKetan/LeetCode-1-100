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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            } else {

            }
        }
        return new TreeNode(nums[maxIndex],
                helper(nums, 0, maxIndex - 1),
                helper(nums, maxIndex + 1, nums.length - 1));
    }

    public TreeNode helper(int[] nums, int low, int high) {
        if (high < low || low > high) {
            return null;
        } else {
            int maxIndex = low;
            for (int i = low; i <= high; i++) {
                if (nums[i] > nums[maxIndex]) {
                    maxIndex = i;
                } else {

                }
            }
            return new TreeNode(nums[maxIndex],
                    helper(nums, low, maxIndex - 1),
                    helper(nums, maxIndex + 1, high));
        }
    }
}