import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {

    private static FastScan fs;
    private static final int mod = 1000000007;

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

    private long solve() {
        int n = fs.nextInt();
        int k = fs.nextInt();
        String s = fs.next();
        long count = 0;
        Stack<Long> powStack = new Stack<>();
        long pow = 1;
        powStack.push(pow);
        for (int i = 1; i <= (n - 1) / 2; i++) {
            pow *= k;
            pow %= mod;
            powStack.push(pow);
        }
        boolean border = false;
        for (int i = 0; i < (n + 1) / 2; i++) {
            count += powStack.pop() * (s.charAt(i) - 97);
            count %= mod;
            if (s.charAt(i) < s.charAt(n - 1 - i)) {
                border = true;
            } else if (s.charAt(i) > s.charAt(n - 1 - i)) {
                border = false;
            }
        }
        count = border ? count + 1 : count;
        return count % 1000000007;
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
