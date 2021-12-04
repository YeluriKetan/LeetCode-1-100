import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        int[][] arr = {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};
        Solution sol = new Solution();
        sol.diagonalSort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(Arrays.toString(arr[i]));
        }
    }
}
