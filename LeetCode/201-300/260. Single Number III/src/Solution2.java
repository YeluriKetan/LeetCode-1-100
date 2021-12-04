import java.util.HashSet;
import java.util.Iterator;

class Solution2 {
    public int[] singleNumber(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (set.contains(nums[i])) {
                set.remove(nums[i]);
            } else {
                set.add(nums[i]);
            }
        }
        int[] ans = new int[2];
        Iterator<Integer> iter = set.iterator();
        ans[0] = iter.next();
        ans[1] = iter.next();
        return ans;
    }
}
