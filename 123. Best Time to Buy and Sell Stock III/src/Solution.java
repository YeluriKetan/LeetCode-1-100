class Solution {
    public int maxProfit(int[] prices) {
        int firstBuy = Integer.MAX_VALUE;
        int firstProfit = Integer.MIN_VALUE;
        int secondBuy = Integer.MAX_VALUE;
        int secondProfit = Integer.MIN_VALUE;
        for (int i = 0; i < prices.length; i++) {
            firstBuy = Math.min(firstBuy, prices[i]);
            firstProfit = Math.max(firstProfit, prices[i] - firstBuy);

            secondBuy = Math.min(secondBuy, prices[i] - firstProfit);
            secondProfit = Math.max(secondProfit, prices[i] - secondBuy);
        }
        return secondProfit;
    }
}
