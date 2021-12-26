import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] points = {{1,3},{-2,2}};
        int[][] ans = sol.kClosest(points, 1);
        Arrays.stream(ans).forEach(x -> System.out.println(Arrays.toString(x)));
    }
}
