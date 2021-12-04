/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

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

    private String ans() {
        int n = fs.nextInt();
        if (n % 2 == 0) {
            fs.nextInt();
            fs.clearLine();
            return "no";
        }
        n = (n - 1) / 2;
        for (int i = 1; i <= n; i++) {
            if (fs.nextInt() != i) {
                fs.clearLine();
                return "no";
            }
        }
        if (fs.nextInt() != n + 1) {
            fs.clearLine();
            return "no";
        }
        for (int i = n; i >= 1; i--) {
            if (fs.nextInt() != i) {
                fs.clearLine();
                return "no";
            }
        }
        return "yes";
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

        public void clearLine() {
            st = null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
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
