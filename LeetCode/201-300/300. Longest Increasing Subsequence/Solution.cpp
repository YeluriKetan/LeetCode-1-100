class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> monoStack;
        monoStack.push_back(nums[0]);
        int end = 0;
        int replacePos;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > monoStack[end]) {
                monoStack.push_back(nums[i]);
                end++;
                continue;
            }
            replacePos = lower_bound(monoStack.begin(), monoStack.end(), nums[i]) - monoStack.begin();
            monoStack[replacePos] = nums[i];
        }
        return end + 1;
    }
};