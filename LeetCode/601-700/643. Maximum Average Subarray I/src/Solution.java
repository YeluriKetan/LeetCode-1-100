class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int max;
        int curr = 0;
        for (int i = 0; i < k; i++) {
            curr += nums[i];
        }
        max = curr;
        for (int i = k; i < nums.length; i++) {
            curr -= nums[i - k];
            curr += nums[i];
            max = Math.max(max, curr);
        }
        return (double) max / (double) k;
    }
}