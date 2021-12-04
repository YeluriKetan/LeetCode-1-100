import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {2, 3, 4, 7};
        int maxBit = 3;
        System.out.println(Arrays.toString(sol.getMaximumXor(arr, maxBit)));
    }
}
