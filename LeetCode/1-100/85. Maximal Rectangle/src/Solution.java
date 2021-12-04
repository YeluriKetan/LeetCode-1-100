import java.util.Stack;

class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        int max = 0;
        for (int j = 0; j < matrix[0].length; j++) {
            matrix[0][j] -= 48;
        }
        for (int i = 1; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 48) {
                    matrix[i][j] = 0;
                } else {
                    matrix[i][j] = (char) (matrix[i - 1][j] + 1);
                }
            }
        }
        for (char[] chars : matrix) {
            max = Math.max(max, maxRectArea(chars));
        }
        return max;
    }

    private int maxRectArea(char[] arr) {
        Stack<Integer> monoStack = new Stack<>();
        int currArea;
        int max = 0;
        int prevIndex;
        int currIndex = 0;
        int len = arr.length;

        while (currIndex < len) {
            if (monoStack.empty() || arr[monoStack.peek()] <= arr[currIndex]) {
                monoStack.push(currIndex++);
            } else {
                prevIndex = monoStack.pop();
                currArea = arr[prevIndex] * (monoStack.empty() ? currIndex : currIndex - monoStack.peek() - 1);

                if (max < currArea) {
                    max = currArea;
                }
            }
        }

        while (!monoStack.empty()) {
            prevIndex = monoStack.pop();
            currArea = arr[prevIndex] * (monoStack.empty() ? currIndex : currIndex - monoStack.peek() - 1);

            if (max < currArea) {
                max = currArea;
            }
        }

        return max;
    }
}
