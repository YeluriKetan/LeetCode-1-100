import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] arr = {{1,0},{2,0},{3,1},{3,2}};
        System.out.println(Arrays.toString(sol.findOrder(4, arr)));
    }
}
