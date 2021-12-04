class Solution {
    public int maxProduct(int[] nums) {
        int totatMax = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        int temp;
        for (int i = 1; i < nums.length; i++) {
            temp = Math.max(nums[i], Math.max(nums[i] * currMax, nums[i] * currMin));
            currMin = Math.min(nums[i], Math.min(nums[i] * currMax, nums[i] * currMin));
            currMax = temp;
            totatMax = Math.max(totatMax, currMax);
        }
        return totatMax;
    }
}
