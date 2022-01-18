class Solution {

public:
    inline static vector<int> memo;

    inline static void init() {
        memo.push_back(1);
        int pointers[3] = {0, 0, 0};
        int values[3] = {2, 3, 5};
        int minVal;
        for (int i = 0; i < 1689; ++i) {
            minVal = INT_MAX;
            for (int j = 0; j < 3; ++j) {
                minVal = min(minVal, memo[pointers[j]] * values[j]);
            }
            for (int j = 0; j < 3; ++j) {
                if (minVal == memo[pointers[j]] * values[j]) {
                    pointers[j]++;
                }
            }
            memo.push_back(minVal);
        }
    }

    int nthUglyNumber(int n) {
        if (memo.empty()) {
            init();
        }
        return memo[n - 1];
    }
};