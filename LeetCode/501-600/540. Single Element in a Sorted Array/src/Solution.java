class Solution {
    public int singleNonDuplicate(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums[nums.length - 1] != nums[nums.length - 2]) {
            return nums[nums.length - 1];
        }
        int low = 0;
        int high = (nums.length - 3) / 2;
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            mid *= 2;
            if (nums[mid] != nums[mid + 1]) {
                high = mid / 2;
            } else {
                low = mid / 2 + 1;
            }
        }
        return nums[low * 2];
    }
}
