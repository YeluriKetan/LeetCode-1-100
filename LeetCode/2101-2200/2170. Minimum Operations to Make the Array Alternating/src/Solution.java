import java.util.HashMap;

class Solution {
    public int minimumOperations(int[] nums) {
        HashMap<Integer, Integer> counterMap = new HashMap<>();
        int evenMax = -1, evenMaxCount = 0, evenMax2 = -1, evenMax2Count = 0;
        int temp;
        for (int i = 0; i < nums.length; i += 2) {
            temp = counterMap.getOrDefault(nums[i], 0) + 1;
            if (temp > evenMaxCount) {
                evenMax = nums[i];
                evenMaxCount = temp;
            } else if (temp > evenMax2Count) {
                evenMax2 = nums[i];
                evenMax2Count = temp;
            }
            counterMap.put(nums[i], temp);
        }
        counterMap.clear();
        int oddMax = -1, oddMaxCount = 0, oddMax2 = -1, oddMax2Count = 0;
        for (int i = 1; i < nums.length; i += 2) {
            temp = counterMap.getOrDefault(nums[i], 0) + 1;
            if (temp > oddMaxCount) {
                oddMax = nums[i];
                oddMaxCount = temp;
            } else if (temp > oddMax2Count) {
                oddMax2 = nums[i];
                oddMax2Count = temp;
            }
            counterMap.put(nums[i], temp);
        }
        if (evenMax == oddMax) {
            return Math.min(nums.length - evenMaxCount - oddMax2Count, nums.length - evenMax2Count - oddMaxCount);
        } else {
            return nums.length - evenMaxCount - oddMaxCount;
        }
    }
}
