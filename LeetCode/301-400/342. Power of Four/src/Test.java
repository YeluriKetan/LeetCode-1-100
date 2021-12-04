public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int x = 1;
        while (x != 0) {
            System.out.println("X:" + x + ", " + sol.isPowerOfFour(x));
            x *= 4;
        }
    }
}
