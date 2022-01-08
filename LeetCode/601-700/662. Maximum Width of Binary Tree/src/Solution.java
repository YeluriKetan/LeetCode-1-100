import java.util.Queue;
import java.util.LinkedList;

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
    public int widthOfBinaryTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        if (root.left != null) {
            root.left.val = -1;
            queue.add(root.left);
        }
        if (root.right != null) {
            root.right.val = 1;
            queue.add(root.right);
        }
        if (queue.isEmpty()) {
            return 1;
        }
        queue.add(null);
        TreeNode curr;
        int max = 1;
        int start = queue.peek().val;
        int end = 0;
        while (!queue.isEmpty()) {
            curr = queue.poll();
            if (curr == null) {
                if (Math.signum(end) + Math.signum(start) == 0) {
                    max = Math.max(max, end - start);
                } else {
                    max = Math.max(max, end - start + 1);
                }
                if (!queue.isEmpty()) {
                    start = queue.peek().val;
                    queue.add(null);
                }
                continue;
            }
            if (curr.left != null) {
                curr.left.val = curr.val * 2;
                if (curr.left.val > 0) {
                    curr.left.val--;
                }
                queue.add(curr.left);
            }
            if (curr.right != null) {
                curr.right.val = curr.val * 2;
                if (curr.right.val < 0) {
                    curr.right.val++;
                }
                queue.add(curr.right);
            }
            end = curr.val;
        }
        return max;
    }
}
