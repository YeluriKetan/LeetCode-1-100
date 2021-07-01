public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {1,2,0,0,2,1};
        int[] res = sol.avoidFlood(arr);
        System.out.print("[");
        for (int i = 0; i < res.length; i++) {
            System.out.print(res[i] + ", ");
        }
        System.out.println("]");
    }
}
