class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int pivot = (int) Math.pow(2, maximumBit);
        int[] res = new int[nums.length];
        int currXor = 0;
        for (int i = 0; i < nums.length; i++) {
//            System.out.print(currXor);
            currXor = currXor ^ nums[i];
//            System.out.print(", " + currXor + ", " + (currXor % pivot));
            res[nums.length - 1 - i] = pivot - 1 - (currXor % pivot);
//            System.out.println(", " + res[i]);
        }
        return res;
    }
}