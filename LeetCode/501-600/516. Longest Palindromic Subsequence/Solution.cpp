class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 1) {
            return 1;
        }
        int dp[n][n];
        int maxLen;
        dp[0][n - 1] = s[0] == s[n - 1] ? 2 : 0;
        for (int i = n - 2; i > 0; --i) {
            dp[0][i] = s[0] == s[i] ? 2 : dp[0][i + 1];
        }
        dp[0][0] = 1;
        maxLen = max(dp[0][0], dp[0][1]);
        for (int i = 1; i < n - 1; ++i) {
            dp[i][n - 1] = s[i] == s[n - 1] ? 2 : dp[i - 1][n - 1];
            for (int j = n - 2; j > i; --j) {
                dp[i][j] = s[i] == s[j] ? dp[i - 1][j + 1] + 2 : max(dp[i - 1][j], dp[i][j + 1]);
            }
            dp[i][i] = dp[i - 1][i + 1] + 1;
            maxLen = max(maxLen, max(dp[i][i], dp[i][i + 1]));
        }
        return maxLen;
    }
};