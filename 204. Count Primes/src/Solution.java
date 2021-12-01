class Solution {
    public int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }
        boolean[] bool = new boolean[n];
        int count = 1;
        for (int i = 3; i < n; i += 2) {
            if (!bool[i]) {
                count++;
                for (int j = 3 * i; j < n; j += 2 * i) {
                    bool[j] = true;
                }
            }
        }
        return count;
    }
}
