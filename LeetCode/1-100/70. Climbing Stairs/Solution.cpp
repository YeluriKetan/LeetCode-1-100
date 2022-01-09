class Solution {
    int memo[46] = {0, 1, 2};
    int done = 2;

public:
    int climbStairs(int n) {
        for (int i = done + 1; i <= n; ++i) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        done = n;
        return memo[n];
    }
};