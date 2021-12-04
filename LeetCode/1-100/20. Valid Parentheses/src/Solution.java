import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        if (s.length() % 2 != 0) {
            return false;
        }
        Stack<Character> stack = new Stack<>();
        char c1;
        char c2;
        for (int i = 0; i < s.length(); i++) {
            c2 = s.charAt(i);
            if (stack.empty()) {
                stack.push(c2);
                continue;
            }
            c1 = stack.peek();
            if (c1 == '(' && c2 == ')') {
                stack.pop();
            } else if (c1 == '[' && c2 == ']') {
                stack.pop();
            } else if (c1 == '{' && c2 == '}') {
                stack.pop();
            } else if (c2 == '(' || c2 == '[' || c2 == '{') {
                stack.push(c2);
            } else {
                return false;
            }
        }
        return stack.empty();
    }
}
