class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int prevUp, prevDown;
        prevUp = prevDown = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                prevUp = prevDown + 1;
            } else if (nums[i] < nums[i - 1]) {
                prevDown = prevUp + 1;
            }
        }
        return max(prevUp, prevDown);
    }
};