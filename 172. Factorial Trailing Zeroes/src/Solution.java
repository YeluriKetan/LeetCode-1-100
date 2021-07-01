class Solution {
    public int trailingZeroes(int n) {
        char count = 0;
        char power = 5;
        while (power <= n) {
            count += n / power;
            power *= 5;
        }
        return count;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.trailingZeroes(100));
    }
}