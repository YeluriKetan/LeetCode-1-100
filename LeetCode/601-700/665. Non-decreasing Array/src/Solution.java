class Solution {
    public boolean checkPossibility(int[] nums) {
        boolean drop = false;
        if (nums.length == 1) {
            return true;
        }
        if (nums[0] > nums[1]) {
            drop = true;
        }
        for (int i = 1; i < nums.length - 2; i++) {
            if (nums[i] > nums[i + 1]) {
                if (drop) {
                    return false;
                } else {
                    if (nums[i - 1] > nums[i + 1] && nums[i] > nums[i + 2]) {
                        return false;
                    } else {
                        drop = true;
                    }
                }
            }
        }
        if (nums.length != 2 && nums[nums.length - 2] > nums[nums.length - 1]) {
            if (drop) {
                return false;
            }
        }
        return true;
    }
}