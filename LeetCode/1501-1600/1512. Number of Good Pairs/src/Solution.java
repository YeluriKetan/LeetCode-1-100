import java.util.HashMap;

class Solution {
    public int numIdenticalPairs(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>(nums.length);
        int count = 0;
        int curr;
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                curr = map.get(nums[i]);
                count += curr;
                map.replace(nums[i], curr + 1);
            } else {
                map.put(nums[i], 1);
            }
        }
        return count;
    }
}