// TODO NOT DONE
/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {

    private static FastScan fs;
    private static BufferedWriter bw;
    private static int[] pow1 = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    private static int[] pow2 = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};

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

    private long ans() {
        int n = fs.nextInt();
        long l = fs.nextLong();
        long r = fs.nextLong();
        int[] arr = new int[n];
        long total = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = fs.nextInt();
        }
        long min = 0;
        long max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 9; j++) {
                if ((long) arr[i] * pow1[j + 1] + pow1[j] >= l) {
                    min = (long) arr[i] * pow1[j];
                    break;
                }
            }
            for (int j = 6; j >= 0; j--) {
                if ((long) arr[i] * pow1[j + 1] + pow2[j] <= r) {
                    max = (long) arr[i] * pow1[j + 1] + pow2[j];
                    break;
                }
            }
            for (int j = 0; j < n; j++) {
                if (arr[j] >= min && arr[j] <= max) {
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
