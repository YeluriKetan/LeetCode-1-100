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

        int total = fs.nextInt();
        for (int i = 1; i <= total; i++) {
            bw.write("Case #" + i + ": " + sol.solve() + "\n");
        }
        bw.flush();
        fs.close();
    }

    private int solve() {
        long G = fs.nextLong();
        long maxDays = (long) ((Math.sqrt(1 + (8 * G)) - 1) / 2);
        long curr;
        int total = 0;
        for (long i = 1; i <= maxDays; i++) {
            curr = (2 * G) - (i * i) + i;
            if (curr % (2 * i) == 0) {
                total++;
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

        private long nextLong() {
            return Long.parseLong(next());
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
