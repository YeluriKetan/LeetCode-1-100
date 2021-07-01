class Solution {
    char[] str;
    public boolean validPalindrome(String s) {
        str = s.toCharArray();
        if (str.length < 2) {
            return true;
        }
        char point1 = 0;
        char point2 = (char) (str.length - 1);
        while (point1 < (str.length + 1) / 2 && point2 >= point1) {
            if (str[point1] == str[point2]) {
                point1++;
                point2--;
            } else {
                return valid(point1, (char) (point2 - 1)) ||
                        valid((char) (point1 + 1), point2);
            }
        }
        return true;
    }

    public boolean valid(char point1, char point2) {
        char n = (char) (point2 - point1 + 1);
        if (n < 2) {
            return true;
        }
        while (point2 >= point1) {
            if (str[point1] == str[point2]) {
                point1++;
                point2--;
            } else {
                return false;
            }
        }
        return true;
    }
}