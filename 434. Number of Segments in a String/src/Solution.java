class Solution {
    public int countSegments(String s) {
        char count = 0;
        boolean counted = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                counted = false;
            } else {
                if (!counted) {
                    count++;
                    counted = true;
                }
            }
        }
        return count;
    }
}
