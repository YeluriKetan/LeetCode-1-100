/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {

    private static FastScan fs;
    private static BufferedWriter bw;
    private static String[] pow = new String[60];

    private Codechef() {
        long curr = 1;
        for (int i = 0; i < 60; i++) {
            curr *= 2;
            pow[i] = String.valueOf(curr - 1);
        }
    }

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

    private String ans() throws IOException {
        long curr = fs.nextLong();
        if (curr == 0) {
            return "2\n1 1";
        }
        BitSet set = toBinary(curr);
        int prevIndex = set.previousSetBit(61);
        int count = 0;
        int currIndex;

        StringBuilder sb = new StringBuilder();
        sb.append(pow[prevIndex - 1]).append(" ");
        count++;

        while ((currIndex = set.previousSetBit(prevIndex - 1)) > 0) {
            if (currIndex == prevIndex - 1) {
                prevIndex = currIndex;
                continue;
            }
            sb.append(pow[prevIndex - 2]).append(" ");
            sb.append(pow[currIndex - 1]).append(" ");
            count += 2;
            prevIndex = currIndex;
        }

        if (prevIndex > 1) {
            sb.append(pow[prevIndex - 2]).append(" ");
            count++;
        }

        return sb.insert(0, count + "\n").toString();
    }

    private static BitSet toBinary(long number) {
        int index = 0;
        BitSet set = new BitSet();
        while (number > 0) {
            index++;
            if (number % 2 == 1) {
                set.set(index);
            }
            number = number / 2;
        }
        return set;
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
