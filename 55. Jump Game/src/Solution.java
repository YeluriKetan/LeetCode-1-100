import java.util.BitSet;

class Solution {

    private static int[] nums;
    private static BitSet memo;

    public boolean canJump(int[] nums) {
        Solution.nums = nums;
        memo = new BitSet();
        boolean ans = dp(0);
        return ans;
    }

    private boolean dp(int curr) {
        if (!memo.get(curr)) {
            if (curr + nums[curr] >= nums.length - 1) {
                return true;
            } else {
                for (int i = nums[curr]; i > 0; i--) {
                    if (dp(curr + i)) {
                        return true;
                    }
                }
            }
        }
        memo.set(curr);
        return false;
    }
}
