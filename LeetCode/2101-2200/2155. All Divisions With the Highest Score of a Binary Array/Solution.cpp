class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int rightOnesCount = accumulate(nums.begin(), nums.end(), 0);
        int maxScore = -1;
        int leftZeroesCount = 0;
        int currScore;
        for (int i = 0; i < n; ++i) {
            currScore = leftZeroesCount + rightOnesCount;
            maxScore = max(maxScore, currScore);
            if (nums[i]) {
                rightOnesCount--;
            } else {
                leftZeroesCount++;
            }
            nums[i] = currScore;
        }
        currScore = leftZeroesCount + rightOnesCount;
        maxScore = max(maxScore, currScore);
        nums.push_back(currScore);
        for (int i = 0; i < n + 1; ++i) {
            if (nums[i] == maxScore) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};