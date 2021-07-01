import java.util.List;
import java.util.Stack;

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = 0;
        for (int i = 0; i < candies.length; i++) {
            max = Math.max(max, candies[i]);
        }
        Stack<Boolean> list = new Stack<Boolean>();
        for (int i = 0; i < candies.length; i++) {
            list.push(candies[i] + extraCandies > max);
        }
        return list;
    }
}