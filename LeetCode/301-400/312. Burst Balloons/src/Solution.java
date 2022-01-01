class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] numsExp = new int[n + 2];
        System.arraycopy(nums, 0, numsExp, 1, n);
        numsExp[0] = 1;
        numsExp[n + 1] = 1;
        int right;
        int[][] dp = new int[n + 2][n + 2];
        for (int interval = 1; interval <= n; interval++) {
            for (int left = 1; left <= n - interval + 1; left++) {
                right = left + interval - 1;
                for (int i = left; i <= right; i++) {
                    dp[left][right] = Math.max(dp[left][right],
                            dp[left][i - 1] + numsExp[left - 1] * numsExp[i] * numsExp[right + 1] + dp[i + 1][right]);
                }
            }
        }
        return dp[1][n];
    }
}
