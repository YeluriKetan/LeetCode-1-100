class Solution {
    public int minAddToMakeValid(String S) {
        char left = 0;
        char count = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '(') {
                left++;
            } else {
                if (left == 0) {
                    count++;
                } else {
                    left--;
                }
            }
        }
        return count + left;
    }
}