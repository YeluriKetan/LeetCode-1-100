public class Test {
    public static void main(String[] args) {
        int[] arr = new int[]{8,1,2,2,3};
        Solution sol = new Solution();
        int[] arr1 = sol.smallerNumbersThanCurrent(arr);
        for (int i = 0; i < arr1.length; i++) {
            System.out.println(arr1[i]);
        };
    }
}
