public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] arr = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
        //int[][] res = sol.countSquares(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print("[");
            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j] + ", ");
            }
            System.out.println("]");
        }
        System.out.println(sol.countSquares(arr));
//        for (int i = 0; i < res.length; i++) {
//            System.out.print("[");
//            for (int j = 0; j < res[0].length; j++) {
//                System.out.print(res[i][j] + ", ");
//            }
//            System.out.println("]");
//        }
    }
}
