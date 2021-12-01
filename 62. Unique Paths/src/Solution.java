class Solution {

    public int uniquePaths(int m, int n) {
        int num = m + n - 2;
        int den = 2;
        if (m - 1 > num / 2) {
            den = m;
            m = n;
            n = den;
            den = 2;
        }
        int ans = 1;
        while (num > n - 1 || den < m) {
            if (den < m && ans % den == 0) {
                ans /= den;
                den++;
            } else if (num > n - 1) {
                ans *= num;
                num--;
            }
        }
        return ans;
    }
}
