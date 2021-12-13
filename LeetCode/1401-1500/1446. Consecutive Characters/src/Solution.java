class Solution {
    public int maxPower(String s) {
        char curr = s.charAt(0);
        int count = 1;
        int max = Integer.MIN_VALUE;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == curr) {
                count++;
            } else {
                max = Math.max(max, count);
                count = 1;
                curr = s.charAt(i);
            }
        }
        max = Math.max(max, count);
        return max;
    }
}
