import java.util.Arrays;

class Solution {
    public void sortColors(int[] nums) {
        int[] colors = new int[3];
        for (int i = 0; i < nums.length; i++) {
            colors[nums[i]]++;
        }
        colors[1] += colors[0];
        colors[2] += colors[1];
        Arrays.fill(nums, 0, colors[0], 0);
        Arrays.fill(nums, colors[0], colors[1], 1);
        Arrays.fill(nums, colors[1], colors[2], 2);
    }
}
