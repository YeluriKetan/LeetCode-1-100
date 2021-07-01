class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] newNums = new int[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            if (i % 2 == 0) {
                newNums[i] = nums[i / 2];
            } else {
                newNums[i] = nums[((i - 1) / 2) + n];
            }
        }
        return newNums;
    }
}