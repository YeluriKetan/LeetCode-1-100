class Solution {
    public String breakPalindrome(String palindrome) {
        if (palindrome.length() == 1) {
            return "";
        }
        StringBuilder str = new StringBuilder(palindrome);
        for (int i = 0; i < (palindrome.length()) / 2; i++) {
            if (palindrome.charAt(i) != 'a') {
                return str.replace(i, i + 1, "a").toString();
            }
        }
        return str.replace(palindrome.length() - 1, palindrome.length(), "b").toString();
    }
}