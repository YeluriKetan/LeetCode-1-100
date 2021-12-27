class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int prevMax = values[0];
        int max = Integer.MIN_VALUE;
        for (int j = 1; j < values.length; j++) {
            max = Math.max(max, prevMax + values[j] - j);
            prevMax = Math.max(prevMax, values[j] + j);
        }
        return max;
    }
}
