/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {

    private static FastScan fs;
    private static final long mod = Long.parseLong("1164778184719273153");

    public static void main (String[] args) throws java.lang.Exception {
        fs = new FastScan();
        Codechef codechef = new Codechef();
        int num = fs.nextInt();
        for (int i = 0; i < num; i++) {
            codechef.ans();
        }
        fs.close();
    }

    private void ans() {
        System.out.println("? " + mod + "\n");
        long mod1 = mod - fs.nextLong() - 1;
        System.out.println("? " + mod1 + "\n");
        long mod2 = fs.nextLong() + 1;
        System.out.println("! " + mod2 + "\n");
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
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
