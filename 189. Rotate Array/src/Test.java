import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        int[] arr = {-1,-100,3,99};
        Solution sol = new Solution();
        sol.rotate(arr, 2);
        System.out.println(Arrays.toString(arr));
    }
}
