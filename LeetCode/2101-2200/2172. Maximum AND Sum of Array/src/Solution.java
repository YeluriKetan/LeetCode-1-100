class Solution {

    // src: https://leetcode.com/problems/maximum-and-sum-of-array/discuss/1766824/JavaC++Python-DP-Solution

    private int[] sNums;
    private int[] memo;
    private int sNumSlots;

    public int maximumANDSum(int[] nums, int numSlots) {
        sNums = nums;
        int maxMask = (int) Math.pow(3, numSlots) - 1;
        memo = new int[maxMask + 1];
        sNumSlots = numSlots;
        return dp(maxMask, nums.length - 1);
    }

    private int dp(int mask, int i) {
        if (memo[mask] > 0) {
            return memo[mask];
        }
        if (i < 0) {
            return 0;
        }
        for (int slot = 1, bit = 1; slot <= sNumSlots; ++slot, bit *= 3) {
            if ((mask / bit) % 3 > 0) {
                memo[mask] = Math.max(memo[mask], (sNums[i] & slot) + dp(mask - bit, i - 1));
            }
        }
        return memo[mask];
    }
}
