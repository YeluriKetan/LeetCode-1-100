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

    private String solve() {
        String n = fs.next();
        int count = 0;
        int len = n.length();
        for (int i = 0; i < len; i++) {
            count += n.charAt(i) - '0';
            count %= 9;
        }
        char toPlace = (char) (((9 - count) % 9) + '0');
        StringBuilder sb = new StringBuilder();
        int pointer = 0;
        if (toPlace == '0') {
            sb.append(n.charAt(0));
            sb.append(toPlace);
            sb.append(n, 1, len);
        } else {
            while (pointer < len && n.charAt(pointer) <= toPlace) {
                pointer++;
            }
            sb.append(n, 0, pointer);
            sb.append(toPlace);
            sb.append(n, pointer, len);
        }
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
