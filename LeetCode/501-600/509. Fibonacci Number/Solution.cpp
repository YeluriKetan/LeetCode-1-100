class Solution {
    int memo[31] = {0, 1};
    int done = 1;

public:
    int fib(int n) {
        for (int i = done + 1; i <= n; ++i) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        done = n;
        return memo[n];
    }
};