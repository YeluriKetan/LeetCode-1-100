class Solution {
    public int[] findErrorNums(int[] nums) {
        boolean[] check = new boolean[nums.length];
        int num = -1;
        for (int i = 0; i < nums.length; i++) {
            if (check[nums[i] - 1]) {
                num = nums[i];
            } else {
                check[nums[i] - 1] = true;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (!check[i]) {
                return new int[]{num, i + 1};
            }
        }
        return new int[0];
    }
}