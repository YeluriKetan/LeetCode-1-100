import java.util.TreeSet;

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (i > k) {
                set.remove(nums[i - k - 1]);
            }
            Integer floor = set.floor(nums[i]);
            Integer ceiling = set.ceiling(nums[i]);
            if (floor != null && (long) nums[i] - (long) floor <= t) {
                return true;
            }
            if (ceiling != null && (long) ceiling - (long) nums[i] <= t) {
                return true;
            }
            set.add(nums[i]);
        }
        return false;
    }
}