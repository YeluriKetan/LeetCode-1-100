import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int[] setCount = new int[nums.length];
        int[] prevIndex = new int[nums.length];
        Arrays.sort(nums);
        int maxCount = Integer.MIN_VALUE;
        int maxPrevIndex = -1;
        int currCount;
        int currPrevIndex;
        for (int i = 0; i < nums.length; i++) {
            currCount = 1;
            currPrevIndex = -1;
            for (int j = i - 1; j > -1; j--) {
                if ((nums[i] % nums[j] == 0) && setCount[j] + 1 > currCount) {
                    currCount = setCount[j] + 1;
                    currPrevIndex = j;
                }
            }
            setCount[i] = currCount;
            prevIndex[i] = currPrevIndex;

            if (currCount > maxCount) {
                maxCount = currCount;
                maxPrevIndex = i;
            }
        }
        List<Integer> list = new LinkedList<>();
        while (maxPrevIndex != -1) {
            list.add(nums[maxPrevIndex]);
            maxPrevIndex = prevIndex[maxPrevIndex];
        }
        return list;
    }
}
