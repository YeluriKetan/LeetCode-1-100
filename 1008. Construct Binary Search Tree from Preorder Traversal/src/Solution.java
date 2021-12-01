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
        return helper(preorder, 0, preorder.length - 1);
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
