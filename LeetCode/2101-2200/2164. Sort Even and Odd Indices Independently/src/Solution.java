import java.util.Arrays;

class Solution {
    public int[] sortEvenOdd(int[] nums) {
        int[] even = new int[(nums.length + 1) / 2];
        int[] odd = new int[nums.length / 2];
        for (int i = 0; i < nums.length; i++) {
            if (i % 2 == 0) {
                even[i / 2] = nums[i];
            } else {
                odd[i / 2] = nums[i];
            }
        }
        Arrays.sort(even);
        Arrays.sort(odd);
        for (int i = 0; i < nums.length; i++) {
            if (i % 2 == 0) {
                nums[i] = even[i / 2];
            } else {
                nums[i] = odd[(nums.length - 1 - i) / 2];
            }
        }
        return nums;
    }
}
