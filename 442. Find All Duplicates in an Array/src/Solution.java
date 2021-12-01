import java.util.BitSet;
import java.util.List;
import java.util.Stack;

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        BitSet set = new BitSet();
        List<Integer> list = new Stack<>();
        for (int i = 0; i < nums.length; i++) {
            if (set.get(nums[i])) {
                list.add(nums[i]);
            } else {
                set.set(nums[i]);
            }
        }
        return list;
    }
}
