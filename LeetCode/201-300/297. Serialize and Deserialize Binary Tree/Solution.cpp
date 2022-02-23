/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        ostringstream ans;
        ans << root->val;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        TreeNode* curr;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                curr = q.front();
                q.pop();
                if (curr == nullptr) {
                    ans << ",.";
                } else {
                    ans << "," << curr->val;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        cout << ans.str() << endl;
        return ans.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        stringstream ss(data);
        string curr;
        getline(ss, curr, ',');
        auto root = new TreeNode(stoi(curr));
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* currNode;
        while (getline(ss, curr, ',')) {
            currNode = q.front();
            q.pop();
            if (curr != ".") {
                currNode->left = new TreeNode(stoi(curr));
                q.push(currNode->left);
            }
            getline(ss, curr, ',');
            if (curr != ".") {
                currNode->right = new TreeNode(stoi(curr));
                q.push(currNode->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));