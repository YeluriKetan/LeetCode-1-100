class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = {0};
        int temp;
        for (int i = 1; i <= amount; ++i) {
            temp = INT_MAX;
            for (int currCoin: coins) {
                if (i - currCoin >= 0 && dp[i - currCoin] > -1) {
                    temp = min(temp, dp[i - currCoin]);
                }
            }
            dp.push_back(temp == INT_MAX ? -1 : temp + 1);
        }
        return dp[amount];
    }
};