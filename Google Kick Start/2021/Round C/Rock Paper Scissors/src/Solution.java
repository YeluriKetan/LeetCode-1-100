import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution {

    private static FastScan fs;

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Solution sol = new Solution();
        fs = new FastScan();

        int num = fs.nextInt();
        fs.nextInt();
        for (int i = 1; i <= num; i++) {
            bw.write("Case #" + i + ": " + sol.solve() + "\n");
        }
        bw.flush();
        fs.close();
    }

    private String solve() {
        double win = fs.nextInt();
        double draw = fs.nextInt();
        double[][][] dp = new double[61][61][61]; // RPS
        char[][][] step = new char[61][61][61];
        dp[1][0][0] = win / 3 + draw / 3;
        step[1][0][0] = 'R';
        dp[0][1][0] = win / 3 + draw / 3;
        step[0][1][0] = 'P';
        dp[0][0][1] = win / 3 + draw / 3;
        step[0][0][1] = 'S';
        double currN;
        double temp;
        double max = -1;
        int x = -1, y = -1, z = -1;
        for (int r = 0; r < 61; r++) {
            for (int p = 0; p < 61; p++) {
                for (int s = 0; s < 61; s++) {
                    currN = r + p + s;
                    if (currN < 2 || currN > 60) {
                        continue;
                    }
                    dp[r][p][s] = -1;
                    currN--;
                    if (r > 0) {
                        temp = dp[r - 1][p][s] + ((p / currN) * win) + ((s / currN) * draw);
                        if (temp > dp[r][p][s]) {
                            dp[r][p][s] = temp;
                            step[r][p][s] = 'R';
                        }
                    }
                    if (p > 0) {
                        temp = dp[r][p - 1][s] + ((s / currN) * win) + ((r / currN) * draw);
                        if (temp > dp[r][p][s]) {
                            dp[r][p][s] = temp;
                            step[r][p][s] = 'P';
                        }
                    }
                    if (s > 0) {
                        temp = dp[r][p][s - 1] + ((r / currN) * win) + ((p / currN) * draw);
                        if (temp > dp[r][p][s]) {
                            dp[r][p][s] = temp;
                            step[r][p][s] = 'S';
                        }
                    }
                    if (currN == 59) {
                        if (dp[r][p][s] > max) {
                            max = dp[r][p][s];
                            x = r;
                            y = p;
                            z = s;
                        }
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 60; i++) {
            sb.append(step[x][y][z]);
            switch (step[x][y][z]) {
            case 'R':
                x--;
                break;
            case 'P':
                y--;
                break;
            case 'S':
                z--;
                break;
            default:
                break;
            }
        }
        sb.reverse();
        return sb.toString();
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
