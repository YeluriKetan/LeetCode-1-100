class Solution {

    private static int[][] gridS;
    private static int r;
    private static int c;
    private static int total;

    public int islandPerimeter(int[][] grid) {
        r = grid.length;
        c = grid[0].length;
        gridS = grid;
        total = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (gridS[i][j] == 1) {
                    helper(i, j);
                }
            }
        }
        return total;
    }

    private void helper(int i, int j) {
        if (i == 0 || gridS[i - 1][j] == 0) {
            total++;
        }
        if (i == r - 1 || gridS[i + 1][j] == 0) {
            total++;
        }
        if (j == 0 || gridS[i][j - 1] == 0) {
            total++;
        }
        if (j == c - 1 || gridS[i][j + 1] == 0) {
            total++;
        }
    }
}
