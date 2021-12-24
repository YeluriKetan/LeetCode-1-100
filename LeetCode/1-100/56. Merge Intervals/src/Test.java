import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] arr = {{1,3},{2,6},{8,10},{15,18}};
        Arrays.stream(sol.merge(arr)).forEach(x -> System.out.print(Arrays.toString(x) + ", "));
    }
}
