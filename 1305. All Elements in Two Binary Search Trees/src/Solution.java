import java.util.ArrayList;
import java.util.List;

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
    ArrayList<Integer> set = new ArrayList<>();
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        adder(root1);
        adder(root2);
        set.sort(Integer::compareTo);
        return set;
    }

    public void adder(TreeNode root) {
        if (root == null) {
            return ;
        } else {
            if (root.left != null) { adder(root.left); }
            set.add(root.val);
            if (root.right != null) { adder(root.right); }
        }
    }
}