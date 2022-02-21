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
    vector<vector<int>> ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        ans.clear();
        vector<int> path;
        pathSumRecurse(root, targetSum, path);
        return ans;
    }

    void pathSumRecurse(TreeNode* root, int targetSum, vector<int> &path) {
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            ans.emplace_back(path);
        }
        if (root->left != nullptr) {
            pathSumRecurse(root->left, targetSum, path);
        }
        if (root->right != nullptr) {
            pathSumRecurse(root->right, targetSum, path);
        }
        path.pop_back();
    }
};