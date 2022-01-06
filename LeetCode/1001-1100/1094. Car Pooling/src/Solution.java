class Solution {

    public boolean carPooling(int[][] trips, int capacity) {
        int[] tracker = new int[1001];
        int max = -1;
        for (int[] trip : trips) {
            tracker[trip[1]] += trip[0];
            tracker[trip[2]] -= trip[0];
            max = Math.max(max, trip[2]);
        }
        int curr = 0;
        for (int i = 0; i <= max; i++) {
            curr += tracker[i];
            if (curr > capacity) {
                return false;
            }
        }
        return true;
    }
}
