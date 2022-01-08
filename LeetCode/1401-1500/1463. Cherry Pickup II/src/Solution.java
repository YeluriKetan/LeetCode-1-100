class Solution {

    public int cherryPickup(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[][] currRow = new int[c][c];
        int[][] nextRow = new int[c][c];
        int currMax;
        for (int row = r - 1; row > -1; row--) {
            for (int a = 0; a < c; a++) {
                for (int b = a; b < c; b++) {
                    currMax = -1;
                    for (int aa = Math.max(0, a - 1); aa <= Math.min(c - 1, a + 1); aa++) {
                        for (int bb = Math.max(aa, b - 1); bb <= Math.min(c - 1, b + 1); bb++) {
                            currMax = Math.max(currMax, nextRow[aa][bb]);
                        }
                    }
                    if (a == b) {
                        currRow[a][b] = currMax + grid[row][a];
                    } else {
                        currRow[a][b] = currMax + grid[row][a] + grid[row][b];
                    }
                }
            }
            int[][] holder = currRow;
            currRow = nextRow;
            nextRow = holder;
        }
        return nextRow[0][c - 1];
    }
}
