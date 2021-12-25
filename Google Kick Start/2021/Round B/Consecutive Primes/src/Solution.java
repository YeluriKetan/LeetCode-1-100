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
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Solution sol = new Solution();
        fs = new FastScan();

        long total = fs.nextLong();
        for (int i = 1; i <= total; i++) {
            bw.write("Case #" + i + ": " + sol.solve() + "\n");
        }
        bw.flush();
        fs.close();
    }

    private long solve() {
        long n = fs.nextLong();
        long[] arr = new long[3];
        int index = 0;
        for (long i = (long) Math.sqrt(n); i > 1 && index < 2; i--) {
            if (isPrime(i)) {
                arr[index++] = i;
            }
        }
        for (long i = (long) Math.sqrt(n) + 1; i < n && index < 3; i++) {
            if (isPrime(i)) {
                arr[index++] = i;
            }
        }
        if (arr[2] * arr[0] > n) {
            return arr[1] * arr[0];
        } else {
            return arr[2] * arr[0];
        }
    }

    private boolean isPrime(long curr) {
        if (curr > 2 && curr % 2 == 0) {
            return false;
        }
        for (int i = 3; i <= Math.sqrt(curr); i += 2) {
            if (curr % i == 0) {
                return false;
            }
        }
        return true;
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
