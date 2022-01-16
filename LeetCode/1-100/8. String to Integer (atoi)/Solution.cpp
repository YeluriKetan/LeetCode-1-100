class Solution {

    void append(bool* canContinue, long long* val, char next) {
        if (next < '0' || next > '9') {
            *canContinue = false;
            return;
        }
        if (*val < 0) {
            *val = (*val * 10) - (next - '0');
        } else {
            *val = (*val * 10) + next - '0';
        }
        if (*val > INT_MAX) {
            *canContinue = false;
            *val = INT_MAX;
        } else if (*val < INT_MIN) {
            *canContinue = false;
            *val = INT_MIN;
        }
    }

public:
    int myAtoi(string s) {
        bool canContinue = true;
        long long ans = 0;
        int sign = 1;
        int index = 0;
        char curr;
        int n = s.size();
        while (index < n) {
            curr = s[index++];
            if (curr == ' ') {
                continue;
            }
            if (curr == '-') {
                sign = -1;
            } else if (curr == '+') {
            } else {
                index--;
            }
            break;
        }
        while (ans == 0 && canContinue && index < n) {
            curr = s[index++];
            append(&canContinue, &ans, curr);
        }
        ans *= sign;
        while (canContinue && index < n) {
            curr = s[index++];
            append(&canContinue, &ans, curr);
        }
        return ans;
    }
};