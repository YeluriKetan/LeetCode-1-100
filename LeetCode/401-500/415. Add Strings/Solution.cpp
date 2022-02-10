class Solution {
public:
    string addStrings(string num1, string num2) {
        string *big, *small;
        if (num1.size() > num2.size()) {
            big = &num1;
            small = &num2;
        } else {
            big = &num2;
            small = &num1;
        }
        int bigPointer = big->size() - 1;
        int smallPointer = small->size() - 1;
        int carry = 0;
        while (smallPointer > -1) {
            carry += big[0][bigPointer] - '0' + small[0][smallPointer] - '0';
            big[0][bigPointer] = '0' + carry % 10;
            carry /= 10;
            bigPointer--;
            smallPointer--;
        }
        while (carry > 0 && bigPointer > -1) {
            carry += big[0][bigPointer] - '0';
            big[0][bigPointer] = '0' + carry % 10;
            carry /= 10;
            bigPointer--;
        }
        if (carry > 0) {
            char currChar = '0' + carry;
            return currChar + big[0];
        } else {
            return big[0];
        }
    }
};