class Solution {
    public boolean checkOnesSegment(String s) {
        boolean check = false;
        for (int i = 0; i < s.length(); i++) {
            if (!check && s.charAt(i) == '0') {
                check = true;
            } else if (s.charAt(i) == '0') {
                //
            } else if (check) {
                return false;
            }
        }
        return true;
    }
}