class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int currCoin: coins) {
            for (int i = currCoin; i <= amount; ++i) {
                dp[i] += dp[i - currCoin];
            }
        }
        return dp[amount];
    }
};