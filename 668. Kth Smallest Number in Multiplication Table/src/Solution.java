class Solution {
    public int findKthNumber(int m, int n, int k) {
        int low = 0;
        int high = m * n;
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (isMoreThankK(mid, m, n, k)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    private boolean isMoreThankK(int mid, int m, int n, int k) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += Math.min(mid / i, n);
        }
        return count >= k;
    }
}
