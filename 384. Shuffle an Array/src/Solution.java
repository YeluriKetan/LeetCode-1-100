import java.util.Arrays;
import java.util.Iterator;
import java.util.Random;
import java.util.TreeSet;

class Solution {

    private static int[] master;
    private static int len;
    private static Random rand;
    private static TreeSet<Pair> set;

    public Solution(int[] nums) {
        master = nums;
        len = master.length;
        rand = new Random();
        set = new TreeSet<>();
    }

    public int[] reset() {
        return Arrays.copyOf(master, len);
    }

    public int[] shuffle() {
        set.clear();
        for (int i = 0; i < len; i++) {
            set.add(new Pair(rand.nextInt(), master[i]));
        }
        int[] curr = new int[len];
        Iterator<Pair> iter = set.iterator();
        for (int i = 0; i < len; i++) {
            curr[i] = iter.next().value;
        }
        return curr;
    }

    private class Pair implements Comparable<Pair> {
        public int random;
        public int value;

        public Pair(int random, int value) {
            this.random = random;
            this.value = value;
        }

        @Override
        public int compareTo(Pair o) {
            if (random == o.random) {
                return Integer.compare(value, o.value);
            } else {
                return Integer.compare(random, o.random);
            }
        }
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
