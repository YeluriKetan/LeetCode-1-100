public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr1 = {1,5,9,1,5,9};
        int[] arr2 = {-2147483648,2147483647};
        System.out.println(sol.containsNearbyAlmostDuplicate(arr1, 2, 3));
        System.out.println("expecting false");
        System.out.println(sol.containsNearbyAlmostDuplicate(arr2, 1, 0));
        System.out.println("expecting false");
    }
}
