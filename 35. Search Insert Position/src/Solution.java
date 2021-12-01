import java.util.Arrays;

class Solution {
    public int searchInsert(int[] nums, int target) {
        int ans = Arrays.binarySearch(nums, target);
        return ans > -1 ? ans : - 1 - ans;
    }
}
