class Solution {

    private static int[] arr = new int[46];

    public int climbStairs(int n) {
        if (arr[n] > 0) {
            return arr[n];
        }
        if (n < 3) {
            arr[n] = n;
            return n;
        } else {
            int curr = climbStairs(n - 1) + climbStairs(n - 2);
            arr[n] = curr;
            return curr;
        }
    }
}
