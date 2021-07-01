class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int[][] result = new int[rowSum.length][colSum.length];
        for (int i = 0; i < rowSum.length; i++) {
            for (int j = 0; j < colSum.length; j++) {
                rowSum[i] = rowSum[i] - (result[i][j] = Math.min(rowSum[i], colSum[j]));
                colSum[j] = colSum[j] - result[i][j];
                if (rowSum[i] == 0) {
                    break;
                }
            }
        }
        return result;
    }
}