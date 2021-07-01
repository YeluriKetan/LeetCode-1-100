public class Test {
    public static void main(String[] args) {
        int[][] arr = {{0,5},{1,2},{0,2},{0,5},{1,3}};
        Solution sol = new Solution();
        int[] ans = sol.findingUsersActiveMinutes(arr, 5);
        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i]);
        }
    }
}
