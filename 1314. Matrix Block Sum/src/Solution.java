class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int sum;
        int[][] accum = new int[mat.length][mat[0].length];
        for (int i = 0; i < mat.length; i++) {
            sum = 0;
            for (int j = 0; j < k && j < mat[0].length; j++) {
                sum += mat[i][j];
            }
            for (int j = 0; j < mat[0].length; j++) {
                if (j + k < mat[0].length) {
                    sum += mat[i][j + k];
                }
                if (j - k - 1 >= 0) {
                    sum -= mat[i][j - k - 1];
                }
                accum[i][j] = sum;
            }
        }
        for (int j = 0; j < mat[0].length; j++) {
            sum = 0;
            for (int i = 0; i < k && i < mat.length; i++) {
                sum += accum[i][j];
            }
            for (int i = 0; i < mat.length; i++) {
                if (i + k < mat.length) {
                    sum += accum[i + k][j];
                }
                if (i - k - 1 >= 0) {
                    sum -= accum[i - k - 1][j];
                }
                mat[i][j] = sum;
            }
        }
        return mat;
    }
}