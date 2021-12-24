import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (x, y) -> {
            if (x[0] == y[0]) {
                return Integer.compare(x[1], y[1]);
            } else {
                return Integer.compare(x[0], y[0]);
            }
        });
        ArrayList<int[]> ans = new ArrayList<>();
        int begin = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= end) {
                end = Math.max(end, intervals[i][1]);
            } else {
                int[] newArr = {begin, end};
                ans.add(newArr);
                begin = intervals[i][0];
                end = intervals[i][1];
            }
        }
        int[] newArr = {begin, end};
        ans.add(newArr);
        return ans.toArray(new int[ans.size()][]);
    }
}
