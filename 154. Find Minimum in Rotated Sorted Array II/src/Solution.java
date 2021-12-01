class Solution {
    public int findMin(int[] nums) {
        int low = 0;
        int high = nums.length - 1;
        if (nums[low] < nums[high]) {
            return nums[low];
        }
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] < nums[high]) {
                high = mid;
            } else if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high--;
            }
        }
        return nums[high];
    }
}
