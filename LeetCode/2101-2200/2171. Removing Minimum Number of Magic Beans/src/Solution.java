import java.util.Arrays;

class Solution {
    public long minimumRemoval(int[] beans) {
        Arrays.sort(beans);
        long totalSum = 0;
        for (int curr: beans) {
            totalSum += curr;
        }
        long minRem = totalSum - ((long) beans[0] * beans.length);
        long preSum = beans[0];
        totalSum -= beans[0];
        long temp;
        for (int i = 1; i < beans.length; i++) {
            if (beans[i] == beans[i - 1]) {
                totalSum -= beans[i];
                preSum += beans[i];
                continue;
            }
            temp = beans.length - i;
            temp *= beans[i];
            temp = preSum + totalSum - temp;
            minRem = Math.min(minRem, temp);
            preSum += beans[i];
            totalSum -= beans[i];
        }
        return minRem;
    }
}
