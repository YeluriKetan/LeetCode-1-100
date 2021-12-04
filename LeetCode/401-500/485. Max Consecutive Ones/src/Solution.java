class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                int curr = 0;
                while (i < nums.length && nums[i] == 1) {
                    curr++;
                    i++;
                }
                max = Math.max(max, curr);
            }
        }
        return max;
    }
}