import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {

    private static FastScan fs;

    public static void main(String[] args) throws IOException {
        Solution sol = new Solution();
        fs = new FastScan();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int total = fs.nextInt();
        for (int i = 1; i <= total; i++) {
            bw.write("Case #" + i + ": " + sol.solve() + "\n");
        }
        bw.flush();
        fs.close();
    }

    private int solve() {
        int r = fs.nextInt();
        int c = fs.nextInt();
        int[][] grid = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = fs.nextInt();
            }
        }
        int[][][] accum = new int[r][c][4]; // top, bottom, left, right
        for (int j = 0; j < c; j++) {
            accum[0][j][0] = grid[0][j];
            accum[r - 1][j][1] = grid[r - 1][j];
        }
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    accum[i][j][0] = accum[i - 1][j][0] + 1;
                }
                if (grid[r - 1 - i][j] == 1) {
                    accum[r - 1 - i][j][1] = accum[r - i][j][1] + 1;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            accum[i][0][2] = grid[i][0];
            accum[i][c - 1][3] = grid[i][c - 1];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (grid[i][j] == 1) {
                    accum[i][j][2] = accum[i][j - 1][2] + 1;
                }
                if (grid[i][c - 1 - j] == 1) {
                    accum[i][c - 1 - j][3] = accum[i][c - j][3] + 1;
                }
            }
        }
        int total = 0;
        int[] temp = new int[2];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 2; l < 4; l++) {
                        temp[0] = accum[i][j][k];
                        temp[1] = accum[i][j][l];
                        Arrays.sort(temp);
                        if (temp[0] < 2) {
                            continue;
                        }
                        total += temp[0] / 2 - 1;
                        total += Math.min(temp[1] / 2, temp[0]) - 1;
                    }
                }
            }
        }
        return total;
    }

    private static class FastScan {
        private BufferedReader br;
        private StringTokenizer st;

        private FastScan() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        private String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
            return st.nextToken();
        }

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private void close() {
            try {
                br.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
}
