class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int left, right, currSum;
        for (int i = 0; i < n - 2; ++i) {
            left = i + 1;
            right = n - 1;
            while (left < right) {
                currSum = nums[i] + nums[left] + nums[right];
                if (currSum < 0) {
                    left++;
                } else if (currSum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (left < right && nums[left - 1] == nums[left]) {
                        left++;
                    }
                    right--;
                    while (right > left && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else {
                    right--;
                }
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return ans;
    }
};