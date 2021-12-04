import java.util.Arrays;

class Solution {
    private static int[] arr;
    private static int len;
    private static int partSum;

    public boolean canPartitionKSubsets(int[] nums, int k) {
        if (k == 1) {
            return true;
        }

        int total = 0;
        for (int num : nums) {
            total += num;
        }
        if (total % k != 0) {
            return false;
        }
        partSum = total / k;
        Arrays.sort(nums);
        arr = nums;
        len = arr.length;
        if (nums[len - 1] > partSum) {
            return false;
        }

        boolean[] used = new boolean[len];
        used[len - 1] = true;
        return helper(k - 1, partSum - nums[len - 1], len - 1, used);
    }

    private boolean helper(int partitionsLeft, int sumLeft, int limit, boolean[] used) {
        if (sumLeft == 0) {
            if (partitionsLeft == 0) {
                return true;
            } else {
                return helper(partitionsLeft - 1, partSum, len - 1, used);
            }
        }

        for (int i = limit; i > -1; i--) {
            if (used[i]) {
                continue;
            }

            if (arr[i] > sumLeft) {
                continue;
            }

            used[i] = true;
            boolean check = helper(partitionsLeft, sumLeft - arr[i], i - 1, used);
            used[i] = false;
            if (check) {
                return true;
            }
        }
        return false;
    }
}
