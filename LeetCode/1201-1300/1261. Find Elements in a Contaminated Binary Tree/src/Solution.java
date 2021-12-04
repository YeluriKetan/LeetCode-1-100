import java.util.HashSet;

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
class FindElements {

    private TreeNode root;
    private HashSet<Integer> set = new HashSet<>();

    public FindElements(TreeNode root) {
        this.root = root;
        root.val = 0;
        FEBuilder(root);
    }

    private void FEBuilder(TreeNode node) {
        set.add(node.val);
        if (node.left != null) {
            node.left.val = 2 * node.val + 1;
            FEBuilder(node.left);
        }
        if (node.right != null) {
            node.right.val = 2 * node.val + 2;
            FEBuilder(node.right);
        }
    }

    public boolean find(int target) {
        return set.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */