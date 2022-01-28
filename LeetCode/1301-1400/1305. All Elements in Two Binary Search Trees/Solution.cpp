class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> sortVec1;
        getSortVecFromTree(root1, &sortVec1);
        vector<int> sortVec2;
        getSortVecFromTree(root2, &sortVec2);
        vector<int> ansVec;
        int n1 = sortVec1.size();
        int n2 = sortVec2.size();
        int point1 = 0;
        int point2 = 0;
        while (point1 < n1 && point2 < n2) {
            if (sortVec1[point1] < sortVec2[point2]) {
                ansVec.push_back(sortVec1[point1++]);
            } else {
                ansVec.push_back(sortVec2[point2++]);
            }
        }
        while (point1 < n1) {
            ansVec.push_back(sortVec1[point1++]);
        }
        while (point2 < n2) {
            ansVec.push_back(sortVec2[point2++]);
        }
        return ansVec;
    }

    void getSortVecFromTree(TreeNode* root, vector<int>* sortVec) {
        if (root == nullptr) {
            return;
        }
        getSortVecFromTree(root->left, sortVec);
        sortVec->push_back(root->val);
        getSortVecFromTree(root->right, sortVec);
    }
};