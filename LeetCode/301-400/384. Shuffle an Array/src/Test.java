import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        int[] arr = {1,2,3};
        Solution solution = new Solution(arr);
        System.out.println(Arrays.toString(solution.shuffle()));
        System.out.println(Arrays.toString(solution.reset()));
        System.out.println(Arrays.toString(solution.shuffle()));
    }
}
