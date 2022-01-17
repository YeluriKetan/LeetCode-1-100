class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[n + 1];
        dp[n] = 1;
        dp[n - 1] = (s[n - 1] != '0');
        for (int i = n - 2; i > -1; --i) {
            dp[i] = 0;
            if (s[i] != '0') {
                dp[i] += dp[i + 1];
            }
            if (s[i] == '1') {
                dp[i] += dp[i + 2];
            } else if (s[i] == '2' && s[i + 1] < '7') {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};