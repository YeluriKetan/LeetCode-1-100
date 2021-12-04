/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {

    private static FastScan fs;
    private static BufferedWriter bw;
    private static final int[] arr = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912};

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
        int k = fs.nextInt();
        if (k == 0) {
            bw.write("YES\n0\n");
            return;
        }
        int curr = k;
        int index = 0;
        while (true) {
            curr -= arr[index];
            if (curr < arr[index++]) {
                break;
            }
        }
        if (curr == 0) {
            curr = 1;
            bw.write("YES\n" + index + "\n" + curr + "\n");
            for (int i = 0; i < index - 1; i++) {
                curr += arr[i];
                bw.write(curr + "\n");
            }
        } else {
            bw.write("NO\n");
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
