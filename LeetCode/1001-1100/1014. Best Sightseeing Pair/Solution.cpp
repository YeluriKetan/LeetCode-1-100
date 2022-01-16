class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxScore = INT_MIN;
        int prevMax = values[0];
        for (int i = 1; i < n; ++i) {
            maxScore = max(maxScore, prevMax + values[i] - i);
            prevMax = max(prevMax, values[i] + i);
        }
        return maxScore;
    }
};