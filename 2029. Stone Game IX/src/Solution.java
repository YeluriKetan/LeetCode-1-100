class Solution {
    public boolean stoneGameIX(int[] stones) {
        int[] track = new int[3];
        for (int i = 0; i < stones.length; i++) {
            track[stones[i] % 3]++;
        }
        if (track[1] + track[2] == 0) {
            return false;
        }
        int max = Math.max(track[1], track[2]);
        int min = Math.min(track[1], track[2]);
        if (track[0] % 2 == 0) {
            return min > 0;
        } else {
            return max > min + 2;
        }
    }
}
