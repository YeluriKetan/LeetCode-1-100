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
        HashMap<String, Integer> map = new HashMap<>();
        int total = 0;
        int currTotal;
        boolean hand;
        boolean newHand;
        for (int i = 0; i < n; i++) {
            String word = fs.nextWord();
            if (map.containsKey(word)) {
                total += map.get(word);
                continue;
            }
            currTotal = 2;
            hand = hand(word.charAt(0));
            for (int j = 1; j < word.length(); j++) {
                newHand = hand(word.charAt(j));
                if (newHand == hand) {
                    currTotal += 4;
                } else {
                    currTotal += 2;
                    hand = newHand;
                }
            }
            map.put(word, currTotal / 2);
            total += currTotal;
        }
        return total;
    }

    private static boolean hand(char c) {
        return  (c == 100 || c == 102);
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

        public String nextWord() {
            return next();
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
