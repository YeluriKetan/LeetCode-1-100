class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int e = 0;
        int o = 1;
        int[] arr = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0) {
                arr[e] = nums[i];
                e += 2;
            } else {
                arr[o] = nums[i];
                o += 2;
            }
        }
        return arr;
    }
}