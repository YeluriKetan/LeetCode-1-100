import java.util.Arrays;
import java.util.TreeMap;

class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int total = 0;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < nums.length; i++) {
            total += nums[i];
            map.merge(nums[i], 1, (x, y) -> x + y);
        }
        if (total % k != 0) {
            return false;
        }
        Arrays.sort(nums);
        for (int i = 0; i < ; i++) {

        }
    }
}
