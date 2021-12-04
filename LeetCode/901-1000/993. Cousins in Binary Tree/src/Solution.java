import java.util.Deque;
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
    public boolean isCousins(TreeNode root, int x, int y) {
        Deque<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        while (!q.isEmpty()) {
            TreeNode curr = q.poll();
            if (curr == null) {
                if (q.isEmpty()) {
                    break;
                }
                q.add(null);
                continue;
            }
            if (curr.val == x) {
                while (q.peek() != null) {
                    TreeNode otherCurr = q.poll();
                    if (otherCurr.val == y) {
                        return true;
                    }
                }
                return false;
            }
            if (curr.val == y) {
                while (q.peek() != null) {
                    TreeNode otherCurr = q.poll();
                    if (otherCurr.val == x) {
                        return true;
                    }
                }
                return false;
            }
            if (curr.left != null && curr.right != null) {
                if (curr.left.val == x && curr.right.val == y) {
                    return false;
                }
                if (curr.left.val == y && curr.right.val == x) {
                    return false;
                }
            }
            if (curr.left != null) {
                q.add(curr.left);
            }
            if (curr.right != null) {
                q.add(curr.right);
            }
        }
        return false;
    }
}
