import java.util.Arrays;

class Solution {

    private static int[] memo;
    private static int doneTill;

    public Solution() {
        memo = new int[10001];
        Arrays.fill(memo, 10002);
        memo[0] = 0;
        doneTill = 0;
    }

    public int numSquares(int n) {
        if (n <= doneTill) {
            return memo[n];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                memo[i] = Math.min(memo[i], 1 + memo[i - j * j]);
            }
        }

        doneTill = n;
        return memo[n];
    }
}
