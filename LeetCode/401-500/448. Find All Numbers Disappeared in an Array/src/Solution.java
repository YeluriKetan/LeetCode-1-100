import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        int prev;
        int curr;
        for (int i = 0; i < n; i++) {
            curr = nums[i];
            while (curr != 0 && nums[curr - 1] != 0) {
                prev = curr;
                curr = nums[prev - 1];
                nums[prev - 1] = 0;
            }
        }
        List<Integer> list = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                list.add(i + 1);
            }
        }
        return list;
    }
}
