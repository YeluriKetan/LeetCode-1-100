import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

public class Solution {

    private static FastScan fs;
    private static final String format = "%s is ruled by %s.";
    private static final Pattern vowel = Pattern.compile("(?i)[aeiou]");
    private static final Pattern y = Pattern.compile("(?i)[y]");

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
        String kingdom = fs.next();
        String lastLetter = kingdom.substring(kingdom.length() - 1);
        String ruler = "Bob";
        if (vowel.matcher(lastLetter).matches()) {
            ruler = "Alice";
        } else if (y.matcher(lastLetter).matches()) {
            ruler = "nobody";
        }
        return String.format(format, kingdom, ruler);
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
