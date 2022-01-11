/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        int ans = 0;
        root->val <<= 1;
        if (root->left != nullptr) {
            root->left->val += root->val;
            ans += sumRootToLeaf(root->left);
        }
        if (root->right != nullptr) {
            root->right->val += root->val;
            ans += sumRootToLeaf(root->right);
        }
        return ans;
    }
};
