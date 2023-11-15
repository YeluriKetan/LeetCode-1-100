import java.util.Arrays;
import java.util.List;

class Solution {
    public int sumCounts(List<Integer> nums) {
        int n = nums.size();
        int ans = 0;
        boolean[] seen = new boolean[n];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int count = 0;
                for (int k = i; k <= j; k++) {
                    if (!seen[nums.get(k)]) {
                        count++;
                        seen[nums.get(k)] = true;
                    }
                }
                ans += count * count;
                Arrays.fill(seen, false);
            }
        }
        return ans;
    }
}
