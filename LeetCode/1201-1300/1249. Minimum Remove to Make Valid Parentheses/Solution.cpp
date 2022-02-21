class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> parentheses;
        int index = 0;
        char temp;
        while (index < s.size()) {
            temp = s[index];
            if (temp == '(') {
                parentheses.push(index);
            } else if (temp == ')') {
                if (parentheses.empty()) {
                    s[index] = 0;
                } else {
                    parentheses.pop();
                }
            }
            index++;
        }
        while (!parentheses.empty()) {
            s[parentheses.top()] = 0;
            parentheses.pop();
        }
        string ans = "";
        for (auto curr: s) {
            if (curr != 0) {
                ans += curr;
            }
        }
        return ans;
    }
};