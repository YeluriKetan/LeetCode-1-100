import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++) {
            Integer val = map.get(target - nums[i]);
            if (val == null) {
                map.put(nums[i], i);
            } else {
                return new int[] {i, val};
            }
        }
        return new int[] {};
    }
}