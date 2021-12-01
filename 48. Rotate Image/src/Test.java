import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        int[][] mat = {{1}};
        Solution sol = new Solution();
        sol.rotate(mat);
        for (int i = 0; i < mat.length; i++) {
            System.out.println(Arrays.toString(mat[i]));
        }
    }
}
