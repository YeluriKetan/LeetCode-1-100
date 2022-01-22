class Solution {
    int dp[101][101];

public:
    Solution() {
        for (int i = 0; i < 101; ++i) {
            dp[0][i] = 1;
        }
        long long temp;
        for (int i = 1; i < 101; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j < 101; ++j) {
                temp = dp[i - 1][j];
                temp += dp[i][j - 1];
                dp[i][j] = temp < INT_MAX ? temp : 0;
            }
        }
    }

    int uniquePaths(int m, int n) {
        return dp[m - 1][n - 1];
    }
};