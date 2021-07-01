class Solution {
    public int countSquares(int[][] matrix) {
        int[][] sum = new int[matrix.length + 1][matrix[0].length + 1];
        int count = 0;
        for (int i = 1; i < sum.length ; i++) {
            for (int j = 1; j < sum[0].length; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    sum[i][j] = Math.min(Math.min(sum[i][j - 1], sum[i - 1][j]), sum[i - 1][j - 1]) + 1;
                    count += sum[i][j];
                }
            }
        }
        return count;
    }
}