class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (auto &curr: columnTitle) {
            ans *= 26;
            ans += curr - 'A' + 1;
        }
        return ans;
    }
};
