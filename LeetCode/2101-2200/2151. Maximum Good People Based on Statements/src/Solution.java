class Solution {

    private static final int[] pow = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};

    public int maximumGood(int[][] statements) {
        int max = 0;
        int n = statements.length;
        int currCount;
        for (int i = (1 << n) - 1; i > 0; i--) {
            currCount = Integer.bitCount(i);
            if (currCount > max && check(statements, i, n)) {
                max = currCount;
            }
        }
        return max;
    }

    private boolean check(int[][] statements, int map, int n) {
        for (int i = 0; i < n; i++) {
            if ((map & pow[i]) == 0) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (statements[i][j] == 2) {
                    continue;
                }
                if (statements[i][j] != ((map & pow[j]) >> j)) {
                    return false;
                }
            }
        }
        return true;
    }
}
