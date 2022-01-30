class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - (k % n);
        if (k == 0) {
            return;
        }
        for (int i = 0; i < k / 2; ++i) {
            swap(nums[i], nums[k - i - 1]);
        }
        for (int i = k; i < (n + k) / 2; ++i) {
            swap(nums[i], nums[n - i + k - 1]);
        }
        reverse(nums.begin(), nums.end());
    }
};