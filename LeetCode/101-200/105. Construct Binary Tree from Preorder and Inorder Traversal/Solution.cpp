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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = inorder.size() - 1; i > -1; --i) {
            inMap[inorder[i]] = i;
        }
        return buildTreeRecurse(preorder, 0, preorder.size() - 1,
                                inorder, 0, inorder.size() - 1,
                                inMap);
    }

    TreeNode* buildTreeRecurse(vector<int> &preorder, int preBegin, int preEnd,
                               vector<int> &inorder, int inBegin, int inEnd,
                               unordered_map<int, int> &inMap) {
        if (preBegin > preEnd || inBegin > inEnd) {
            return nullptr;
        }
        int inPointer = inMap[preorder[preBegin]];
        int leftLen = inPointer - inBegin;
        auto currRoot = new TreeNode(preorder[preBegin]);
        currRoot->left = buildTreeRecurse(preorder, preBegin + 1, preBegin + leftLen, inorder, inBegin, inPointer - 1, inMap);
        currRoot->right = buildTreeRecurse(preorder, preBegin + leftLen + 1, preEnd, inorder, inPointer + 1, inEnd, inMap);
        return currRoot;
    }
};
