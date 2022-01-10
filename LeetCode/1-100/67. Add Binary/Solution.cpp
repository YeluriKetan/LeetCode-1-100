class Solution {
public:
    string addBinary(string a, string b) {
        int aSize = a.size();
        int bSize = b.size();
        int n = max(a.size(), b.size()) + 2;
        char ans[n];
        char carry = 0;
        ans[n - 1] = '\0';
        for (int i = 0; i < n - 1; ++i) {
            if (i < aSize) {
                carry += a[aSize - 1 - i] - '0';
            }
            if (i < bSize) {
                carry += b[bSize - 1 - i] - '0';
            }
            ans[n - 2 - i] = '0' + (carry % 2);
            carry /= 2;
        }
        if (ans[0] == '1') {
            return ans;
        } else {
            return ans + 1;
        }
    }
};
