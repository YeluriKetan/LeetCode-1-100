class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] arr = new int[60];
        for (int curr: time) {
            arr[curr % 60]++;
        }
        int total = 0;
        for (int i = 1; i < 30; i++) {
            total += arr[i] * arr[60 - i];
        }
        total += (arr[0] * (arr[0] - 1)) / 2;
        total += (arr[30] * (arr[30] - 1)) / 2;
        return total;
    }
}
