class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] tracker = new int[n + 1];
        for (int[] ints : trust) {
            tracker[ints[0]]--;
            tracker[ints[1]]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (tracker[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
}
