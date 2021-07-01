class CustomStack {

    private int[] stack;
    private int point;

    public CustomStack(int maxSize) {
        this.stack = new int[maxSize];
        this.point = 0;
    }

    public void push(int x) {
        if (point == stack.length) {

        } else {
            this.stack[point] = x;
            point++;
        }
    }

    public int pop() {
        if (this.point == 0) {
            return -1;
        } else {
            point--;
            return stack[point];
        }
    }

    public void increment(int k, int val) {
        int i = 0;
        while(i < k && i < point) {
            stack[i] = stack[i] + val;
            i++;
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */