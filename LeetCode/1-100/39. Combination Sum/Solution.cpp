class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return dfs(0, candidates, target);
    }

    vector<vector<int>> dfs(int pointer, vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        int currVal = candidates[pointer];
        vector<int> currAppend(target / currVal, currVal);
        if (pointer == candidates.size() - 1) {
            if (target % currVal == 0) {
                ans.push_back(currAppend);
            }
            return ans;
        }
        for (int currSum = target % currVal; currSum <= target; currSum += currVal) {
            for (auto curr: dfs(pointer + 1, candidates, currSum)) {
                curr.insert(curr.end(), currAppend.begin(), currAppend.end());
                ans.push_back(curr);
            }
            if (!currAppend.empty()) {
                currAppend.pop_back();
            }
        }
        return ans;
    }
};