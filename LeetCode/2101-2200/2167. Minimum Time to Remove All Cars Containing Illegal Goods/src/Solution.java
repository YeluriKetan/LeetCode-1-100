class Solution {
    public int minimumTime(String s) {
        int n = s.length();
        if (n == 1) {
            return s.charAt(0) - '0';
        }
        int[] dpLR = new int[n];
        if (s.charAt(0) == '1') {
            dpLR[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == '0') {
                dpLR[i] = dpLR[i - 1];
            } else {
                dpLR[i] = Math.min(i + 1, dpLR[i - 1] + 2);
            }
        }
        int prevRL;
        int currRL = s.charAt(n - 1) == '1' ? 1 : 0;
        int minTime = dpLR[n - 2] + currRL;
        for (int i = n - 2; i > 0; i--) {
            prevRL = currRL;
            if (s.charAt(i) == '0') {
                currRL = prevRL;
            } else {
                currRL = Math.min(n - i, prevRL + 2);
            }
            minTime = Math.min(minTime, dpLR[i - 1] + currRL);
        }
        return minTime;
    }
}
