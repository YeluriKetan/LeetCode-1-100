public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] arr = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
        System.out.println(sol.uniquePathsIII(arr));
        int[][] arr2 = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
        System.out.println(sol.uniquePathsIII(arr2));
    }

}
