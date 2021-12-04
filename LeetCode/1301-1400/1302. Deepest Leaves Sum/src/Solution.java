import java.util.LinkedList;
import java.util.Queue;

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
    public int deepestLeavesSum(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        int count = 0;
        while(!q.isEmpty()) {
            TreeNode curr = q.poll();

            if (curr == null) {
                if (q.isEmpty()) {
                    continue;
                } else {
                    count = 0;
                    q.add(null);
                }
            } else {
                if (curr.left != null) { q.add(curr.left); }
                if (curr.right != null) { q.add(curr.right); }
                if (curr.left == null && curr.right == null) { count+= curr.val; }
            }
        }
        return count;
    }
}