class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(robHelper(nums, 0, nums.size() - 2), robHelper(nums, 1, nums.size() - 1));
    }

    int robHelper(vector<int>& nums, int a, int b) {
        int curr = 0, prev = 0, prevPrev;
        for (int i = a; i <= b; ++i) {
            prevPrev = prev;
            prev = curr;
            curr = max(prev, prevPrev + nums[i]);
        }
        return curr;
    }
};