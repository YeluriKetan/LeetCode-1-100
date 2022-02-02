class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (int curr: nums) {
            if (curr == original) {
                original *= 2;
            } else if (curr > original) {
                return original;
            }
        }
        return original;
    }
};