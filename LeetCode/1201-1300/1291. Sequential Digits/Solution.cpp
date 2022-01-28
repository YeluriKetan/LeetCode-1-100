class Solution {

    vector<int> memo;

public:
    Solution() {
        int prev = 9;
        int add = 1;
        for (int i = 2; i <= 9; ++i) {
            prev += (add * i) + 1;
            memo.push_back(prev);
            add = (add * 10) + 1;
            for (int j = 10 - i - 1; j > 0; --j) {
                prev += add;
                memo.push_back(prev);
            }
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int curr: memo) {
            if (low <= curr && curr <= high) {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};