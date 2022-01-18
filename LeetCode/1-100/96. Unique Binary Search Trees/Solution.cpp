class Solution {

    int memo[20] = {1, 1, 2};
    int done = 2;

public:
    int numTrees(int n) {
        for (int i = done + 1; i <= n; ++i) {
            memo[i] = 0;
            for (int j = 0; j < i; ++j) {
                memo[i] += memo[j] * memo[i - 1 - j];
            }
        }
        done = n;
        return memo[n];
    }
};