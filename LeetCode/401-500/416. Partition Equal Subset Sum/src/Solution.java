class Solution {

    public boolean canPartition(int[] nums) {
        if (nums.length == 1) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        boolean[] memo = new boolean[sum + 1];
        memo[0] = true;
        for (int num : nums) {
            for (int j = sum; j >= num; j--) {
                memo[j] = memo[j] || memo[j - num];
            }
        }
        return memo[sum];
    }
}
