class Solution {

    private static int[] memo;

    public Solution() {
        memo = new int[20];
        memo[0] = 1;
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 5;
    }

    public int numTrees(int n) {
        if (memo[n] > 0 || n == 0) {
            return memo[n];
        }
        int total = 0;
        for (int i = 0; i < n / 2; i++) {
            total += 2 * (numTrees(i) * numTrees(n - 1 - i));
        }
        if (n % 2 == 1) {
            total += numTrees(n / 2) * numTrees(n / 2);
        }
        memo[n] = total;
        return total;
    }
}
