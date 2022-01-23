class Solution {
    public int countElements(int[] nums) {
        int min = nums[0];
        int max = nums[0];
        for (int curr: nums) {
            if (curr < min) {
                min = curr;
            }
            if (curr > max) {
                max = curr;
            }
        }
        int count = 0;
        for (int curr: nums) {
            if (min < curr && curr < max) {
                count++;
            }
        }
        return count;
    }
}
