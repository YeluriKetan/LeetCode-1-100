// todo NOT DONE

// /* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {

    private static Codechef codechef;
    private static Scanner sc;

    public static void main (String[] args) throws java.lang.Exception {
        codechef = new Codechef();
        sc = new Scanner(System.in);
        int num = sc.nextInt();
        for (int i = 0; i < num; i++) {
            codechef.ans();
        }
    }

    private void ans() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int[] subj = new int[n];
        for (int i = 0; i < n; i++) {
            subj[i] = sc.nextInt();
        }
        TreeMap<Int, Integer> map = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            map.put(new Int(sc.nextInt(), i), subj[i] - 1);
        }

        boolean[] bool = new boolean[m];
        int total = 0;
        while (true) {
            if (map.isEmpty()) {
                break;
            }
            Int key = map.firstKey();
            if (key.val > k) {
                break;
            }
            Iterator<Integer> list = map.headMap(new Int(key.val, Integer.MAX_VALUE), true).values().iterator();
            int value = list.next();
            while (list.hasNext()) {
                int currVal = list.next();
                if (!bool[currVal]) {
                    value = currVal;
                    break;
                }
            }
            if (bool[value]) {
                bool[value] = false;
            } else {
                bool[value] = true;
                total++;
            }
            map.remove(key);
            k -= key.val;
        }
        System.out.println(total);
    }

    private class Int implements Comparable<Int> {

        private int val;
        private int sec;

        public Int(int val, int sec) {
            this.val = val;
            this.sec = sec;
        }

        @Override
        public int compareTo(Int o) {
            if (val == o.val) {
                return Integer.compare(sec, o.sec);
            } else {
                return Integer.compare(val, o.val);
            }
        }
    }
}
