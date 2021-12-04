/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.regex.Pattern;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {

    private static FastScan fs;
    private static BufferedWriter bw;

    public static void main (String[] args) throws java.lang.Exception {
        fs = new FastScan();
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Codechef codechef = new Codechef();
        int num = fs.nextInt();
        for (int i = 0; i < num; i++) {
            bw.write(codechef.ans() + "\n");
        }
        fs.close();
        bw.flush();
    }

    private int ans() {
        int n = fs.nextInt();
        String str = fs.nextSent();
        int total = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < Math.min(i + 10, n); j++) {
                if (Math.abs(str.charAt(j) - str.charAt(i)) == j - i) {
                    total++;
                }
            }
        }
        return total;
    }

    private static class FastScan {
        BufferedReader br;
        StringTokenizer st;

        public FastScan() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public void clear() {
            st = null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String nextSent() {
            return next();
        }

        public void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
