import java.util.BitSet;

public class Test {
    public static void main(String[] args) {
        BitSet set = new BitSet();
        int[] arr = {9997,9997,9996,9995,9994,9993,9992,9991,9990,9989,9988,9987,9986,9985,9984,9983,9982,9981,9980};
        Solution sol = new Solution();
        System.out.println(sol.canJump(arr));
    }
}
