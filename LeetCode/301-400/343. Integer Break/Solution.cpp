class Solution {

    int memo[59] = {0, 1, 2, 3};
    int done = 3;

public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        int temp;
        for (int i = done + 1; i <= n; ++i) {
            temp = 1;
            for (int j = 1; j <= i / 2; ++j) {
                temp = max(temp, memo[j] * memo[i - j]);
            }
            memo[i] = temp;
        }
        done = n;
        return memo[n];
    }
};