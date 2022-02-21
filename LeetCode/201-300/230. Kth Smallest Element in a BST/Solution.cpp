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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> inorder;
        while (root != nullptr) {
            inorder.push(root);
            root = root->left;
        }
        TreeNode* curr;
        while (k-- > 1) {
            curr = inorder.top();
            inorder.pop();
            curr = curr->right;
            while (curr != nullptr) {
                inorder.push(curr);
                curr = curr->left;
            }
        }
        return inorder.top()->val;
    }
};