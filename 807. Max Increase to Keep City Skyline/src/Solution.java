class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] topSkyLine = topSkyLine(grid);
        int[] sideSkyLine = sideSkyLine(grid);
        int count = 0;
        for (int i = 0; i < topSkyLine.length; i++) {
            for (int j = 0; j < topSkyLine.length; j++) {
                count+= Math.min(topSkyLine[j], sideSkyLine[i]) - grid[i][j];
            }
        }
        return count;
    }

    public int[] topSkyLine(int[][] grid) {
        int[] arr = new int[grid.length];
        for (int i = 0; i < grid.length; i++) {
            arr[i] = 0;
            for (int j = 0; j < grid.length; j++) {
                arr[i] = Math.max(grid[j][i], arr[i]);
            }
        }
        return arr;
    }

    public int[] sideSkyLine(int[][] grid) {
        int[] arr = new int[grid.length];
        for (int i = 0; i < grid.length; i++) {
            arr[i] = 0;
            for (int j = 0; j < grid.length; j++) {
                arr[i] = Math.max(grid[i][j], arr[i]);
            }
        }
        return arr;
    }
}