public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = sol.minOperations("1");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+",");
        }
    }
}
