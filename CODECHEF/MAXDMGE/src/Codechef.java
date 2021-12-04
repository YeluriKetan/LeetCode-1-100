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
            codechef.ans();
        }
        fs.close();
        bw.flush();
    }

    private void ans() throws IOException {
        int n = fs.nextInt();
        int prev;
        int curr = fs.nextInt();
        int next = fs.nextInt();
        bw.write((curr & next) + " ");
        prev = curr;
        curr = next;
        for (int i = 0; i < n - 2; i++) {
            next = fs.nextInt();
            bw.write(Math.max(prev & curr, curr & next) + " ");
            prev = curr;
            curr = next;
        }
        bw.write((prev & curr) + "\n");
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
