class Solution {
    public int missingNumber(int[] nums) {
        int ans = (nums.length) * (nums.length + 1) / 2;
        for (int i = 0; i < nums.length; i++) {
            ans -= nums[i];
        }
        return ans;
    }
}
