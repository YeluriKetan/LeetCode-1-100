import java.util.HashMap;

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
    private static HashMap<Integer, Integer> MAP;
    private static int[] INORDER;
    private static int[] POSTORDER;

    public Solution() {
        MAP = new HashMap<>();
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        MAP.clear();
        INORDER = inorder;
        POSTORDER = postorder;
        for (int i = 0; i < inorder.length; i++) {
            MAP.put(inorder[i], i);
        }
        return helper(0, inorder.length - 1, 0, postorder.length - 1);
    }

    private TreeNode helper(int InLow, int InHigh, int PoLow, int PoHigh) {
        if (PoLow > PoHigh || InLow > InHigh) {
            return null;
        }

        TreeNode node = new TreeNode();
        int currInd = MAP.get(POSTORDER[PoHigh]);
        node.val = INORDER[currInd];

        if (PoLow == PoHigh) {
            return node;
        }

        node.left = helper(InLow, currInd - 1, PoLow, PoLow + currInd - 1 - InLow);
        node.right = helper(currInd + 1, InHigh, PoHigh - InHigh + currInd, PoHigh - 1);

        return node;
    }
}
