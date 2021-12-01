import java.util.Stack;

class MinStack {

    private static Stack<Integer> values;
    private static Stack<Integer> minValues;

    public MinStack() {
        values = new Stack<>();
        minValues = new Stack<>();
    }

    public void push(int val) {
        values.push(val);
        if (minValues.empty() || minValues.peek() > val) {
            minValues.push(val);
        } else {
            minValues.push(minValues.peek());
        }
    }

    public void pop() {
        values.pop();
        minValues.pop();
    }

    public int top() {
        return values.peek();
    }

    public int getMin() {
        return minValues.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
