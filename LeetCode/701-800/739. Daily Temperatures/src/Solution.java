import java.util.Stack;

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> stack = new Stack<>();
        int[] index = new int[71];
        int len = temperatures.length;

        stack.push(temperatures[len - 1]);
        index[temperatures[len - 1] - 30] = len - 1;
        temperatures[len - 1] = 0;

        int temp;
        for (int i = temperatures.length - 2; i > -1; i--) {
            while (!stack.isEmpty() && stack.peek() <= temperatures[i]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                stack.push(temperatures[i]);
                index[temperatures[i] - 30] = i;
                temperatures[i] = 0;
            } else {
                temp = stack.peek();
                stack.push(temperatures[i]);
                index[temperatures[i] - 30] = i;
                temperatures[i] = index[temp - 30] - i;
            }
        }
        return temperatures;
    }
}
