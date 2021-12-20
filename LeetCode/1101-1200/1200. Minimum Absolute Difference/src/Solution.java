import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int min = Integer.MAX_VALUE;
        for (int i = 1; i < arr.length; i++) {
            min = Math.min(min, arr[i] - arr[i - 1]);
        }
        List<List<Integer>> ans = new LinkedList<>();
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - arr[i - 1] == min) {
                List<Integer> currPair = new LinkedList<>();
                currPair.add(arr[i - 1]);
                currPair.add(arr[i]);
                ans.add(currPair);
            }
        }
        return ans;
    }
}
