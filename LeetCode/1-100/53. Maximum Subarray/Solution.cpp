class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = INT_MIN;
        int currSubArr = 0;
        for (int i = nums.size() - 1; i > -1; --i) {
            currSubArr = max(currSubArr + nums[i], nums[i]);
            maxSub = max(maxSub, currSubArr);
        }
        return maxSub;
    }
};