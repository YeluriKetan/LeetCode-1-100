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

    private int ans() {
        int n = fs.nextInt();
        int a = fs.nextInt();
        int b = fs.nextInt();
        int[] arr = new int[]{0, 0};

        while (n % 2 == 0) {
            n /= 2;
            arr[0]++;
        }

        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                n /= i;
                arr[1]++;
            }
        }

        if (n > 2) {
            arr[1]++;
        }

        if (a > -1 && b > -1) {
            return a * arr[0] + b * arr[1];
        } else if (a > -1) {
            if (arr[0] > 0) {
                return a * arr[0];
            } else {
                return b;
            }
        } else if (b > -1) {
            if (arr[0] > 0) {
                return a + b * arr[1];
            } else {
                return b * arr[1];
            }
        } else {
            if (arr[0] == 0) {
                return b;
            } else {
                return a;
            }
        }
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
