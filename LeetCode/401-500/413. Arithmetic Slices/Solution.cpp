class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int nextDiff = 10000;
        int nextLen = 0;
        int total = 0;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] - nums[i - 1] == nextDiff) {
                total += ++nextLen - 1;
            } else {
                nextDiff = nums[i] - nums[i - 1];
                nextLen = 1;
            }
        }
        return total;
    }
};