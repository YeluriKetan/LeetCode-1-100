class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int nextNext = 0, next = 0, curr = 0, maxNext = prices[n - 1];
        if (n > 1) {
            next = max(nextNext, prices[n - 1] - prices[n - 2]);
            maxNext = max(maxNext, prices[n - 2]);
        }
        if (n == 2) {
            return next;
        }
        for (int i = n - 3; i > -1; --i) {
            curr = max(next, maxNext - prices[i]);
            maxNext = max(maxNext, prices[i] + nextNext);
            nextNext = next;
            next = curr;
        }
        return curr;
    }
};