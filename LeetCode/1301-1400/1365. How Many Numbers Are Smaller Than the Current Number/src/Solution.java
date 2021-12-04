import java.util.HashMap;

class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>(102, 1);
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], 1 + map.get(nums[i]));
            } else {
                map.put(nums[i], 1);
            }
        }
        char[] index = new char[101];
        index[0] = 0;
        char curr = 0;
        if (map.containsKey(0)) {
            //do nothing
        } else {
            map.put(0, 0);
        }
        for (char i = 1; i < 101; i++) {
            if (map.containsKey((int) i)) {
                index[i] = (char) (index[curr] + map.get((int) curr));
                curr = i;
            } else {
                //do nothing
            }
        }
        int[] given = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            given[i] = index[nums[i]];
        }
        return given;
    }
}