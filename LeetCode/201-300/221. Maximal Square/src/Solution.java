class Solution {
    public int maximalSquare(char[][] matrix) {
        int ans = 0;
        for (int j = 0; j < matrix[0].length; j++) {
            matrix[0][j] -= '0';
            if (ans == 0 && matrix[0][j] == 1) {
                ans = 1;
            }
        }
        for (int i = 1; i < matrix.length; i++) {
            matrix[i][0] -= '0';
            if (ans == 0 && matrix[i][0] == 1) {
                ans = 1;
            }
            for (int j = 1; j < matrix[0].length; j++) {
                if (matrix[i][j] == '1') {
                    matrix[i][j] = (char) (Math.min(matrix[i - 1][j - 1], Math.min(matrix[i][j - 1], matrix[i - 1][j])) + 1);
                    ans = Math.max(ans, matrix[i][j]);
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        return ans * ans;
    }
}
