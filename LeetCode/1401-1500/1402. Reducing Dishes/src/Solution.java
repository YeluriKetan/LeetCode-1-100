import java.util.Arrays;

class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int cumm = 0;
        int accum = 0;
        int index = satisfaction.length - 1;
        while (index > -1) {
            accum += satisfaction[index];
            if (accum <= 0) {
                break;
            }
            cumm += accum;
            index--;
        }
        return cumm;
    }
}