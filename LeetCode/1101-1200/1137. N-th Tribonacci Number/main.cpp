class Solution {
    int memo[38] = {0, 1, 1};
    int done = 2;

public:
    int tribonacci(int n) {
        for (int i = done + 1; i <= n; ++i) {
            memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
        }
        done = n;
        return memo[n];
    }
};