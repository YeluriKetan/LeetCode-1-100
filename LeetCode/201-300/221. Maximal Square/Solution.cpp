class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSq = 0;
        int dp[n];
        int leftUp;
        int temp;
        for (int j = 0; j < n; ++j) {
            dp[j] = matrix[0][j] - '0';
            if (dp[j] > 0) {
                maxSq = 1;
            }
        }
        for (int i = 1; i < m; ++i) {
            temp = matrix[i][0] - '0';
            maxSq = max(maxSq, temp);
            leftUp = dp[0];
            dp[0] = temp;
            for (int j = 1; j < n; ++j) {
                temp = min(dp[j - 1], min(leftUp, dp[j]));
                leftUp = dp[j];
                dp[j] = (matrix[i][j] == '0') ? 0 : temp + 1;
                maxSq = max(maxSq, dp[j]);
            }
        }
        return maxSq * maxSq;
    }
};