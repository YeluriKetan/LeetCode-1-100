import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = {4,1,2};
        int[] nums2 = {1,3,4,2};
        System.out.println(Arrays.toString(sol.nextGreaterElement(nums1, nums2)));
    }
}
