public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] arr = {{1,2,3},{4,5,6},{7,8,9}};
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j] + ",");
            }
            System.out.println("");
        }
        int[][] newArr = sol.matrixBlockSum(arr, 2);
        System.out.println("");
        for (int i = 0; i < newArr.length; i++) {
            for (int j = 0; j < newArr[0].length; j++) {
                System.out.print(newArr[i][j] + ",");
            }
            System.out.println("");
        }
    }
}
