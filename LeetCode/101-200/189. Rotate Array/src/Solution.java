import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public void rotate(int[] nums, int k) {
        Queue<Integer> q = new ArrayDeque<>();
        k = nums.length - (k % nums.length);
        for (int i = 0; i < nums.length; i++) {
            q.add(nums[i]);
            if (i + k < nums.length) {
                nums[i] = nums[i + k];
            } else {
                nums[i] = q.poll();
            }
        }
    }
}
