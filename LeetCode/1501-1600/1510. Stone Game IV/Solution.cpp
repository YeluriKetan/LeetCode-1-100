class Solution {

    bool dp[100001] = {false, true, false};
    int done = 2;
    int squares[317];

public:
    Solution() {
        for (int i = 0; i < 317; ++i) {
            squares[i] = i * i;
        }
    }

    bool winnerSquareGame(int n) {
        for (int i = done + 1; i <= n; ++i) {
            dp[i] = false;
            for (int j = sqrt(i); j > 0; --j) {
                if (!dp[i - squares[j]]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        done = n;
        return dp[n];
    }
};