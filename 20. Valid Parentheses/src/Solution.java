import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        int len = s.length();
        Stack<Character> stack = new Stack<Character>();
        char cIn = s.charAt(0);
        if (cIn == ']' || cIn == ')' || cIn == '}') {
            return false;
        }
        char c1;
        char c3;
        for (int i = 0; i < len; i++) {
            c3 = s.charAt(i);
            if (stack.empty()) {
                if (c3 == '(' || c3 == '[' || c3 == '{') {
                    stack.push(c3);
                    continue;
                } else {
                    return false;
                }
            }
            c1 = stack.peek();
            if (c1 == '(' && c3 == ')') {
                stack.pop();
            } else if (c1 == '[' && c3 == ']') {
                stack.pop();
            } else if (c1 == '{' && c3 == '}') {
                stack.pop();
            } else if (c3 == '(' || c3 == '[' || c3 == '{') {
                stack.push(c3);
            } else {
                return false;
            }
        }
        return stack.empty();
    }
}