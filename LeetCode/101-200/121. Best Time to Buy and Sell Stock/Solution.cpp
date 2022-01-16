class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int prevMin = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            maxProf = max(maxProf, prices[i] - prevMin);
            prevMin = min(prevMin, prices[i]);
        }
        return maxProf;
    }
};