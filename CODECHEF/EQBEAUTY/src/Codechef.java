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

    private long ans() {
        int n = fs.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = fs.nextInt();
        }
        if (n == 2) {
            return 0;
        }
        Arrays.sort(arr);
        if (n == 3) {
            return Math.min(arr[2] - arr[1], arr[1] - arr[0]);
        }
        long min = Long.MAX_VALUE;
        int a = 1;
        int b = n - 2;
        long first, second;
        long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n - 1; i++) {
            sum1 += Math.abs(arr[i] - arr[(n - 1)/2]);
            sum2 += Math.abs(arr[i + 1] - arr[1 + (n - 1)/2]);
        }
        min = sum1;
        min = Math.min(min, sum2);
        while (a < b) {
            first = arr[n - 1] - arr[a];
            second = arr[b] - arr[0];
            min = Math.min(min, Math.abs(first - second));
            if (b == a + 1) {
                break;
            }
            if (first > second) {
                a++;
            } else {
                b--;
            }
        }
        return min;
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
