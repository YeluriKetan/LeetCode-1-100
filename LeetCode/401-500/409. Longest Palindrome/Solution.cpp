class Solution {
public:
    int longestPalindrome(string s) {
        int counter[52] = {0};
        for (char currChar: s) {
            if (currChar > 'Z') {
                counter[26 + currChar - 'a']++;
            } else {
                counter[currChar - 'A']++;
            }
        }
        int total = 0;
        int oddTotal = 0;
        for (int currInt: counter) {
            total += currInt / 2;
            oddTotal += currInt % 2;
        }
        return 2 * total + (oddTotal > 0 ? 1 : 0);
    }
};