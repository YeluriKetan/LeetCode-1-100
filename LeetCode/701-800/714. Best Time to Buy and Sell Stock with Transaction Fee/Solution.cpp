class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int maxNext = max(0, prices[n - 1] - fee);
        int next = 0;
        int curr = 0;
        for (int i = n - 2; i > -1; --i) {
            curr = max(next, maxNext - prices[i]);
            next = curr;
            maxNext = max(maxNext, prices[i] - fee + curr);
        }
        return curr;
    }
};
