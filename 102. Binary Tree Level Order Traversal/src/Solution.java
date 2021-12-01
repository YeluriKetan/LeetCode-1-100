import java.util.LinkedList;
import java.util.List;
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) {
            return new LinkedList<>();
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        TreeNode curr;
        List<List<Integer>> list = new LinkedList<>();
        List<Integer> currList = new LinkedList<>();
        while (!q.isEmpty()) {
            curr = q.poll();
            if (curr == null) {
                list.add(currList);
                currList = new LinkedList<>();
                if (!q.isEmpty()) {
                    q.add(null);
                }
                continue;
            }
            currList.add(curr.val);
            if (curr.left != null) {
                q.add(curr.left);
            }
            if (curr.right != null) {
                q.add(curr.right);
            }
        }
        return list;
    }
}
