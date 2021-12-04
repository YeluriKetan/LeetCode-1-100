public class Test {
    public static void main(String[] args) {
        int[] arr1 = {4,6,5,9,3,7};
        int[] arr2 = {0,0,2};
        int[] arr3 = {2,3,5};
        Solution sol = new Solution();
        System.out.println(sol.checkArithmeticSubarrays(arr1, arr2, arr3).toString());
    }
}
