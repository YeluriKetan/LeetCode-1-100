import java.util.Arrays;

class Solution {

    private static int[] arr;
    private static int[] memo;

    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        arr = nums;
        memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return Math.max(helper(0), helper(1));
    }

    private int helper(int index) {
        if (memo[index] > -1) {
            return memo[index];
        }
        int curr = arr[index];
        if (index + 2 < arr.length) {
            curr = arr[index] + helper(index + 2);
        }
        if (index + 3 < arr.length) {
            curr = Math.max(curr, arr[index] + helper(index + 3));
        }
        memo[index] = curr;
        return curr;
    }
}
