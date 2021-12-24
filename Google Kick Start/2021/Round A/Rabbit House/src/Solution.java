import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
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

    private Pair[][] grid;
    private int r;
    private int c;
    private long total;

    private long solve() {
        r = fs.nextInt();
        c = fs.nextInt();
        grid = new Pair[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = new Pair(i, j, fs.nextInt());
            }
        }
        total = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dfs(grid[i][j]);
            }
        }
        return total;
    }

    private void dfs(Pair currPair) {
        int max = -1;
        if (currPair.x > 0) {
            max = Math.max(max, grid[currPair.x - 1][currPair.y].h);
        }
        if (currPair.x < r - 1) {
            max = Math.max(max, grid[currPair.x + 1][currPair.y].h);
        }
        if (currPair.y > 0) {
            max = Math.max(max, grid[currPair.x][currPair.y - 1].h);
        }
        if (currPair.y < c - 1) {
            max = Math.max(max, grid[currPair.x][currPair.y + 1].h);
        }
        if (max > currPair.h + 1) {
            total += max - 1 - currPair.h;
            currPair.h = max - 1;
        }
        Pair nextPair;
        if (currPair.x > 0) {
            nextPair = grid[currPair.x - 1][currPair.y];
            if (nextPair.h < currPair.h - 1) {
                total += currPair.h - 1 - nextPair.h;
                nextPair.h = currPair.h - 1;
                dfs(nextPair);
            }
        }
        if (currPair.x < r - 1) {
            nextPair = grid[currPair.x + 1][currPair.y];
            if (nextPair.h < currPair.h - 1) {
                total += currPair.h - 1 - nextPair.h;
                nextPair.h = currPair.h - 1;
                dfs(nextPair);
            }
        }
        if (currPair.y > 0) {
            nextPair = grid[currPair.x][currPair.y - 1];
            if (nextPair.h < currPair.h - 1) {
                total += currPair.h - 1 - nextPair.h;
                nextPair.h = currPair.h - 1;
                dfs(nextPair);
            }
        }
        if (currPair.y < c - 1) {
            nextPair = grid[currPair.x][currPair.y + 1];
            if (nextPair.h < currPair.h - 1) {
                total += currPair.h - 1 - nextPair.h;
                nextPair.h = currPair.h - 1;
                dfs(nextPair);
            }
        }
    }

    private static class Pair {
        private int x;
        private int y;
        private int h;


        private Pair(int x, int y, int h) {
            this.x = x;
            this.y = y;
            this.h = h;
        }
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
