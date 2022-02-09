class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int right = 1;
        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            right = max(right, i + 1);
            while (right < n && nums[right] < nums[i] + k) {
                right++;
            }
            if (nums[right] == nums[i] + k) {
                count++;
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return count;
    }
};