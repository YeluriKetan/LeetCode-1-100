import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] firstList = {{0,2},{5,10},{13,23},{24,25}};
        System.out.print("[");
        for (int[] an : firstList) {
            System.out.print(Arrays.toString(an) + ", ");
        }
        System.out.println("]");
        int[][] secondList = {{1,5},{8,12},{15,24},{25,26}};
        System.out.print("[");
        for (int[] an : secondList) {
            System.out.print(Arrays.toString(an) + ", ");
        }
        System.out.println("]");
        int[][] ans = sol.intervalIntersection(firstList, secondList);
        System.out.print("[");
        for (int[] an : ans) {
            System.out.print(Arrays.toString(an) + ", ");
        }
        System.out.println("]");
    }
}
