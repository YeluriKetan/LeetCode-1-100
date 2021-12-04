public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr1 = {1,2,3,0,0,0};
        int[] arr2 = {2,5,6};
        sol.merge(arr1, arr1.length - arr2.length, arr2, arr2.length);
        System.out.print("{");
        for (int i = 0; i < arr1.length; i++) {
            System.out.print(arr1[i] + ", ");
        }
        System.out.print("}");
    }
}
