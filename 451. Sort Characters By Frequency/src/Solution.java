import java.util.Arrays;
import java.util.Iterator;
import java.util.TreeSet;

class Solution {
    public String frequencySort(String s) {
        TreeSet<Pair> set = new TreeSet<>();
        Pair[] arr = new Pair[62];
        char curr;
        Pair currPair;
        for (int i = 0; i < s.length(); i++) {
            curr = s.charAt(i);
            if (curr < 58) {
                currPair = arr[curr - 48];
                if (currPair == null) {
                    currPair = new Pair(curr);
                    set.add(currPair);
                    arr[curr - 48] = currPair;
                } else {
                    set.remove(currPair);
                    currPair.count++;
                    set.add(currPair);
                }
            } else if (curr < 91) {
                currPair = arr[curr - 55];
                if (currPair == null) {
                    currPair = new Pair(curr);
                    set.add(currPair);
                    arr[curr - 55] = currPair;
                } else {
                    set.remove(currPair);
                    currPair.count++;
                    set.add(currPair);
                }
            } else {
                currPair = arr[curr - 61];
                if (currPair == null) {
                    currPair = new Pair(curr);
                    set.add(currPair);
                    arr[curr - 61] = currPair;
                } else {
                    set.remove(currPair);
                    currPair.count++;
                    set.add(currPair);
                }
            }

        }
        StringBuilder str = new StringBuilder();
        Iterator<Pair> iterator = set.iterator();
        while (iterator.hasNext()) {
            currPair = iterator.next();
            for (int i = 0; i < currPair.count; i++) {
                str.append(currPair.charac);
            }
        }
        return str.toString();
    }

    public class Pair implements Comparable<Pair> {
        public int count;
        public char charac;

        public Pair(char charac) {
            this.charac = charac;
            this.count = 1;
        }

        @Override
        public int compareTo(Pair other) {
            if (count == other.count) {
                return Character.compare(charac, other.charac);
            } else {
                return -Integer.compare(count, other.count);
            }
        }

        @Override
        public boolean equals(Object other) {
            if (other == this) {
                return true;
            }

            if (!(other instanceof Pair)) {
                return false;
            }

            return charac == ((Pair) other).charac;
        }
    }
}
