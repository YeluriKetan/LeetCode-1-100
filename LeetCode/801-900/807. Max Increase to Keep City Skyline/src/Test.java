public class Test {
    public static void main(String[] args) {
        int[][] arr = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
        Solution sol = new Solution();
//        int[] topArr = sol.topSkyLine(arr);
//        int[] sideArr = sol.sideSkyLine(arr);
//        for (int i = 0; i < arr.length; i++) {
//            System.out.print(topArr[i]);
//        }
//        System.out.println("");
//        for (int i = 0; i < arr.length; i++) {
//            System.out.print(sideArr[i]);
//        }
        System.out.println(sol.maxIncreaseKeepingSkyline(arr));
    }
}
