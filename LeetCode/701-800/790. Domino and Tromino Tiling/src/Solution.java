class Solution {

    private int[] memo;
    private int done;

    public Solution() {
        memo = new int[1000];
        memo[0] = 1;
        memo[1] = 2;
        memo[2] = 5;
        done = 3;
    }

    public int numTilings(int n) {
        if (n <= done) {
            return memo[n - 1];
        }
        long count;
        for (int i = done; i < n; i++) {
            count = 0;
            count += 2 * memo[i - 1];
            count += memo[i - 3];
            memo[i] = (int) (count % 1000000007);
        }
        done = n;
        return memo[n - 1];
    }
}
