/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {

    private static FastScan fs;
    private static BufferedWriter bw;
    private static final int mod = 1000000007;

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

    private long ans() throws IOException {
        int n = fs.nextInt();
        long total = 0;
        int[] arr0 = new int[(n + 1) / 2];
        int[] arr1 = new int[n / 2];
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                arr0[i / 2] = fs.nextInt();
            } else {
                arr1[(i) / 2] = fs.nextInt();
            }
        }
        Arrays.sort(arr0);
        Arrays.sort(arr1);
        long curr = 0;
        int len = n / 2 - 1;
        if (n % 2 == 0) {
            for (int i = 0; i < arr1.length; i++) {
                bw.write(arr0[len - i] + " " + arr1[i] + " ");
                curr += arr1[len - i];
                total += arr0[i] * curr;
            }
        } else {
            for (int i = 0; i < arr1.length; i++) {
                bw.write(arr0[len + 1 - i] + " " + arr1[i] + " ");
                curr += arr1[len - i];
                total += arr0[i + 1] * curr;
            }
            bw.write(arr0[0] + "");
        }
        bw.write("\n");
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

        public void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
