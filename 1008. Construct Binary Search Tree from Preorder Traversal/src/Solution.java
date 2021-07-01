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
    public TreeNode bstFromPreorder(int[] preorder) {
        if (preorder.length == 1) {
            return new TreeNode(preorder[0]);
        } else {
            int firstMax = -1;
            for (int i = 1; i < preorder.length; i++) {
                if (preorder[i] > preorder[0]) {
                    firstMax = i;
                    break;
                } else {

                }
            }
            if (firstMax == -1) {
                return new TreeNode(preorder[0], helper(preorder, 1, preorder.length - 1), null);
            }
            return new TreeNode(preorder[0],
                    helper(preorder, 1, firstMax - 1),
                    helper(preorder, firstMax, preorder.length - 1));
        }
    }

    public TreeNode helper(int[] preorder, int low, int high) {
        if (high < low) {
            return null;
        } else {
            int firstMax = -1;
            for (int i = low + 1; i <= high; i++) {
                if (preorder[i] > preorder[low]) {
                    firstMax = i;
                    break;
                } else {

                }
            }
            if (firstMax == -1) {
                return new TreeNode(preorder[low], helper(preorder, low + 1, high), null);
            }
            return new TreeNode(preorder[low],
                    helper(preorder, low + 1, firstMax - 1),
                    helper(preorder, firstMax, high));
        }
    }
}