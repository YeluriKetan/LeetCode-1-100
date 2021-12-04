import java.util.Arrays;

class Solution {
    public int maxIceCream(int[] costs, int coins) {
        
        Arrays.sort(costs);
        int count = 0;
        int i = 0;
        while (coins > 0 && i < costs.length) {
            if (costs[i] <= coins) {
                count++;
                coins -= costs[i];
                i++;
            } else {
                break;
            }
        }
        return count;
    }
}