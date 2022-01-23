class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] ans = new int[nums.length];
        int pos = 0;
        int neg = 1;
        for (int curr: nums) {
            if (curr > 0) {
                ans[pos] = curr;
                pos += 2;
            } else {
                ans[neg] = curr;
                neg += 2;
            }
        }
        return ans;
    }
}
