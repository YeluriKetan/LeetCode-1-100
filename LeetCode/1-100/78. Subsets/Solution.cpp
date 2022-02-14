class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        for (auto &i: nums) {
            for (int j = ans.size() - 1; j > -1; --j) {
                vector<int> newVec = ans[j];
                newVec.push_back(i);
                ans.push_back(newVec);
            }
        }
        return ans;
    }
};