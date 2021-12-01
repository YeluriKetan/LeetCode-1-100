import java.util.HashMap;

class Solution {
    public static int[] priceS;
    public static HashMap<Integer, Integer> memo;

    public int maxProfit(int[] prices) {
        priceS = prices;
        memo = new HashMap<>();
        return dp(0);
    }

    private int dp(int index) {
        if (index >= priceS.length - 1) {
            return 0;
        }

        if (memo.containsKey(index)) {
            return memo.get(index);
        }

        int max = Integer.MIN_VALUE;
        for (int i = index + 1; i < priceS.length; i++) {
            if (priceS[i] > priceS[index]) {
                max = Math.max(max, priceS[i] - priceS[index] + dp(i + 2));
            }
        }
        max = Math.max(max, dp(index + 1));

        memo.put(index, max);
        return max;
    }

}
