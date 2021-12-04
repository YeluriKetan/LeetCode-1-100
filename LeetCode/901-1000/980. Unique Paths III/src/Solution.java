class Solution {

    static private int ans, total, count;
    static private boolean[][] visited;
    static private int[][] givenGrid;

    public int uniquePathsIII(int[][] grid) {
        total = 0;
        count = 0;
        ans = 0;
        visited = new boolean[grid.length][grid[0].length];
        givenGrid = grid;

        int x = 0, y = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0) {
                    total++;
                } else if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        visited[x][y] = true;
        if (x - 1 >= 0) {
            helper(x - 1, y);
        }
        if (y + 1 < grid[0].length) {
            helper(x, y + 1);
        }
        if (x + 1 < grid.length) {
            helper(x + 1, y);
        }
        if (y - 1 >= 0) {
            helper(x, y - 1);
        }
        return ans;
    }
    private void helper(int x, int y) {
        visited[x][y] = true;
        if (givenGrid[x][y] == 2) {
            if (count == total) {
                ans++;
            }
        } else if (givenGrid[x][y] == -1) {
        } else {
            count++;
            if (x - 1 >= 0 && !visited[x - 1][y]) {
                helper(x - 1, y);
            }
            if (y + 1 < givenGrid[0].length && !visited[x][y + 1]) {
                helper(x, y + 1);
            }
            if (x + 1 < givenGrid.length && !visited[x + 1][y]) {
                helper(x + 1, y);
            }
            if (y - 1 >= 0 && !visited[x][y - 1]) {
                helper(x, y - 1);
            }
            count--;
        }
        visited[x][y] = false;
    }
}