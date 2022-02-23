/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        dfs(root, p, q);
        return ans;
    }

    int dfs(TreeNode* curr, TreeNode* p, TreeNode* q) {
        if (ans != nullptr) {
            return 3;
        }
        int sum = 0;
        if (curr->left != nullptr) {
            sum += dfs(curr->left, p, q);
        }
        if (curr->right != nullptr) {
            sum += dfs(curr->right, p, q);
        }
        if (curr == p || curr == q) {
            sum += 1;
        }
        if (sum == 2) {
            ans = curr;
            return 3;
        } else {
            return sum;
        }
    }
};