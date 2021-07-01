import java.util.Arrays;

class Solution {
    public int strStr(String haystack, String needle) {
        char n = (char) needle.length();
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < haystack.length() - n + 1; i++) {
            if (haystack.substring(i, i + n).equals(needle)) {
                return i;
            }
        }
        return -1;
    }
}