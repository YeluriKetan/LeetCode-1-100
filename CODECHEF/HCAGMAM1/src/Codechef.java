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

    private int ans() throws IOException {
        int x = fs.nextInt();
        int y = fs.nextInt();
        String str = fs.next();
        int total = 0, longest = 0, curr = 0;
        boolean streak = false;
        for (int i = 0; i < 30; i++) {
            if (str.charAt(i) == 49) {
                total++;
                if (streak) {
                    curr++;
                } else {
                    streak = true;
                    curr = 1;
                }
            } else {
                if (streak) {
                    streak = false;
                    longest = Math.max(longest, curr);
                    curr = 0;
                }
            }
        }
        longest = Math.max(longest, curr);
        return (total * x) + (longest * y);
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

        public void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
