class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] dp = new long[n];
        long max = 0;
        int nextInd;
        long currVal;
        for (int i = n - 1; i > -1; i--) {
            nextInd = i + questions[i][1] + 1;
            currVal = questions[i][0];
            currVal += (nextInd < n) ? dp[nextInd] : 0;
            max = dp[i] = Math.max(max, currVal);
        }
        return dp[0];
    }
}
