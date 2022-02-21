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
class BSTIterator {
    stack<TreeNode*> inorder;

public:
    BSTIterator(TreeNode* root) {
        while (root != nullptr) {
            inorder.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* curr = inorder.top();
        int ans = curr->val;
        inorder.pop();
        curr = curr->right;
        while (curr != nullptr) {
            inorder.push(curr);
            curr = curr->left;
        }
        return ans;
    }

    bool hasNext() {
        return !inorder.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */