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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<vector<int>> ans;
        TreeNode* currNode;
        while (!bfs.empty()) {
            vector<int> currLevel;
            for (int i = bfs.size(); i > 0; --i) {
                currNode = bfs.front();
                bfs.pop();
                currLevel.push_back(currNode->val);
                if (currNode->left != nullptr) {
                    bfs.push(currNode->left);
                }
                if (currNode->right != nullptr) {
                    bfs.push(currNode->right);
                }
            }
            if (ans.size() % 2 == 1) {
                reverse(currLevel.begin(), currLevel.end());
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};