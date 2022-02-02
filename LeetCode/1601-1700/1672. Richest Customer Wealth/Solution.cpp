class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = 0;
        for (vector<int> currAcct: accounts) {
            richest = max(richest, accumulate(currAcct.begin(), currAcct.end(), 0));
        }
        return richest;
    }
};