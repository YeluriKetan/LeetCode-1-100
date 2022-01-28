class Solution {
    int dp[1001] = {1};

public:
    int combinationSum4(vector<int>& nums, int target) {
        long long temp;
        for (int i = 1; i <= target; ++i) {
            temp = 0;
            for (int currNum: nums) {
                if (i >= currNum) {
                    temp += dp[i - currNum];
                }
            }
            dp[i] = temp;
        }
        return dp[target];
    }
};