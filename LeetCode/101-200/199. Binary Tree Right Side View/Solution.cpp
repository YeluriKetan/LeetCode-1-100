class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<int> ans;
        TreeNode* curr;
        int currLevelEnd = -101;
        while (!bfs.empty()) {
            for (int i = bfs.size(); i > 0; --i) {
                curr = bfs.front();
                bfs.pop();
                currLevelEnd = curr->val;
                if (curr->left != nullptr) {
                    bfs.push(curr->left);
                }
                if (curr->right != nullptr) {
                    bfs.push(curr->right);
                }
            }
            ans.push_back(currLevelEnd);
        }
        return ans;
    }
};
