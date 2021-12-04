class Solution {
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if (cloned.val == target.val) {
            return cloned;
        } else {
            TreeNode tree = getTargetCopyer(cloned.left, target);
            if (tree == null) {
                return getTargetCopyer(cloned.right, target);
            } else {
                return tree;
            }
        }
    }

    public TreeNode getTargetCopyer(TreeNode node, TreeNode target) {
        if (node == null) {
            return null;
        } else if (node.val == target.val) {
            return node;
        } else {
            TreeNode tree = getTargetCopyer(node.left, target);
            if (tree == null) {
                return getTargetCopyer(node.right, target);
            } else {
                return tree;
            }
        }
    }
}