class Solution {
    public int[] singleNumber(int[] nums) {
        int xor = 0;
        for (int i = 0; i < nums.length; i++) {
            xor ^= nums[i];
        }
        int index = 0;
        while (true) {
            if ((xor & 1) == 1) {
                break;
            } else {
                index++;
                xor >>= 1;
            }
        }
        int check = (int) Math.pow(2, index);
        int[] ans = {0, 0};
        for (int i = 0; i < nums.length; i++) {
            if ((nums[i] & check) == check) {
                ans[1] ^= nums[i];
            } else {
                ans[0] ^= nums[i];
            }
        }
        return ans;
    }
}
