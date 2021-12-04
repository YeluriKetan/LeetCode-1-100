import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums1.length; i++) {
            map.merge(nums1[i], 1, Integer::sum);
        }
        int index = -1;
        for (int i = 0; i < nums2.length; i++) {
            if (map.containsKey(nums2[i])) {
                if (map.get(nums2[i]) > 0) {
                    index++;
                    nums1[index] = nums2[i];
                    map.merge(nums2[i], -1, Integer::sum);
                }
            }
        }
        return Arrays.copyOfRange(nums1, 0, index + 1);
    }
}
