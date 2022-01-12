class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currMaxSub = nums[0];
        int maxSub = currMaxSub;
        int total = currMaxSub;
        int currMinSub = currMaxSub;
        int minSub = currMinSub;
        for (int i = 1; i < n; ++i) {
            currMaxSub = max(currMaxSub + nums[i], nums[i]);
            maxSub = max(maxSub, currMaxSub);
            currMinSub = min(currMinSub + nums[i], nums[i]);
            minSub = min(minSub, currMinSub);
            total += nums[i];
        }
        maxSub = max(maxSub, total);
        if (minSub != total) {
            maxSub = max(maxSub, total - minSub);
        }
        return maxSub;
    }
};
