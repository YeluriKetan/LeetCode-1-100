class Solution {

    int memo[10001] = {0, 1, 2, 3, 1};
    int done = 4;

public:
    int numSquares(int n) {
        if (n <= done) {
            return memo[n];
        }
        int temp;
        for (int i = done + 1; i <= n; ++i) {
            temp = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                temp = min(temp, memo[i - j * j]);
            }
            memo[i] = 1 + temp;
        }
        done = n;
        return memo[n];
    }
};