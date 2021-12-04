import java.util.ArrayList;
import java.util.HashMap;
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
    HashMap<Integer, List<TreeNode>> map = new HashMap<>();
    public List<TreeNode> allPossibleFBT(int n) {
        if (map.containsKey(n)) {
            return this.map.get(n);
        }
        List<TreeNode> list = new ArrayList<>();
        if (n == 1) {
            list.add(new TreeNode(0, null, null));
            return list;
        }
        for (int i = 1; i < n; i+=2) {
            List<TreeNode> list1 = allPossibleFBT(i);
            List<TreeNode> list2 = allPossibleFBT(n - 1 - i);
            for (TreeNode left: list1) {
                for (TreeNode right: list2) {
                    list.add(new TreeNode(0, left, right));
                }
            }
        }
        this.map.put(n, list);
        return list;
    }
}