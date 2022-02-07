class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSumTracker;
        int n = nums.size();
        unordered_map<int, int>::iterator pointer;
        int sum = 0;
        int maxLen = 0;
        prefixSumTracker[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i] ? 1 : -1;
            pointer = prefixSumTracker.find(sum);
            if (pointer == prefixSumTracker.end()) {
                prefixSumTracker[sum] = i;
            } else {
                maxLen = max(maxLen, i - pointer->second);
            }
        }
        return maxLen;
    }
};