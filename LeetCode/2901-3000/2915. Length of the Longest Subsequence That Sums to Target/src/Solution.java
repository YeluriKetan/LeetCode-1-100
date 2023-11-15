import java.util.List;

class Solution {
    public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
        int[] prevDP = new int[target + 1];
        int[] currDP = new int[target + 1];
        int n = nums.size();
        for (int curr: nums) {
            for (int j = 1; j <= target; j++) {
                if (j - curr < 0) {
                    currDP[j] = prevDP[j];
                } else if (j == curr) {
                    currDP[j] = Math.max(prevDP[j], 1);
                } else {
                    if (prevDP[j - curr] > 0) {
                        currDP[j] = Math.max(prevDP[j], prevDP[j - curr] + 1);
                    } else {
                        currDP[j] = prevDP[j];
                    }
                }
            }
            int[] tempDP = prevDP;
            prevDP = currDP;
            currDP = tempDP;
        }
        return prevDP[target] > 0 ? prevDP[target] : -1;
    }
}
