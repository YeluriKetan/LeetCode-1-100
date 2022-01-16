import java.util.Arrays;

class Solution {
    public long maxRunTime(int n, int[] batteries) {
        Arrays.sort(batteries);
        long total = 0;
        for (int currBat: batteries) {
            total += currBat;
        }
        int ind = batteries.length - 1;
        while (batteries[ind] > total / (n)) {
            total -= batteries[ind--];
            n--;
        }
        return total / (n);
    }
}
