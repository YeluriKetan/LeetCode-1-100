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
        int num = fs.nextInt();
        for (int i = 0; i < num; i++) {
            bw.write(ans() + "\n");
        }
        fs.close();
        bw.flush();
    }

    private static int ans() {
        int n = fs.nextInt();
        long k = fs.nextLong();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = fs.nextInt();
        }
        PriorityQueue<Integer> q;
        BitSet set = new BitSet();
        if (k <= ((long) n * (n + 1)) / 4) {
            q = new PriorityQueue<>(Collections.reverseOrder());
            for (int i = 0; i < n; i++) {
                set.clear();
                for (int j = i; j < n; j++) {
                    set.set(arr[j]);
                    int currClearBit = set.nextClearBit(0);
                    if (q.size() < k) {
                        q.add(currClearBit);
                    } else {
                        if (currClearBit < q.peek()) {
                            q.poll();
                            q.add(currClearBit);
                        }
                    }
                }
            }
        } else {
            q = new PriorityQueue<>();
            k = (((long) n * (n + 1)) / 2) - k + 1;
            for (int i = 0; i < n; i++) {
                set.clear();
                for (int j = i; j < n; j++) {
                    set.set(arr[j]);
                    int currClearBit = set.nextClearBit(0);
                    if (q.size() < k) {
                        q.add(currClearBit);
                    } else {
                        if (currClearBit > q.peek()) {
                            q.poll();
                            q.add(currClearBit);
                        }
                    }
                }
            }
        }
        return q.peek();
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
