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

    private String ans() {
        int n = fs.nextInt();
        int[] arr1 = new int[n];
        for (int i = 0; i < n; i++) {
            arr1[i] = fs.nextInt();
        }
        if (n < 3) {
            for (int i = 0; i < n; i++) {
                if (arr1[i] != fs.nextInt()) {
                    fs.clear();
                    return "NIE";
                }
            }
            return "TAK";
        }
        for (int i = 0; i < n - 2; i++) {
            int diff = fs.nextInt() - arr1[i];
            if (diff < 0) {
                fs.clear();
                return "NIE";
            }
            if (diff != 0) {
                arr1[i] += diff;
                arr1[i + 1] += diff * 2;
                arr1[i + 2] += diff * 3;
            }
        }
        if (arr1[n - 2] != fs.nextInt()) {
            fs.clear();
            return "NIE";
        }
        if (arr1[n - 1] != fs.nextInt()) {
            fs.clear();
            return "NIE";
        }
        return "TAK";
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

        public void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
