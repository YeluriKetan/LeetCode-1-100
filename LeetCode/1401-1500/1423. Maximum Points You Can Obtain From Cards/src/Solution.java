class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int min, sum;
        int num = cardPoints.length - k;
        int currSum = 0;
        for (int i = 0; i < num; i++) {
            currSum += cardPoints[i];
        }
        sum = min = currSum;
        for (int i = num; i < cardPoints.length; i++) {
            sum += cardPoints[i];
            currSum += cardPoints[i];
            currSum -= cardPoints[i - num];
            min = Math.min(currSum, min);
        }
        return sum - min;
    }
}