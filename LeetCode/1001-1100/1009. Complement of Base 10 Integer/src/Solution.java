class Solution {

    private int ans;
    private int a;

    public int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        ans = ~n;
        a = 0;
        while (n > 0) {
            a <<= 1;
            a += 1;
            n >>>= 1;
        }
        return ans & a;
    }
}
