import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        int[] arr = {2, 1, 4};
        Solution sol = new Solution();
        System.out.println(sol.maxProfit(arr));
        System.out.println(Arrays.toString(Solution.priceS));
        System.out.println(Solution.memo.toString());
    }
}
