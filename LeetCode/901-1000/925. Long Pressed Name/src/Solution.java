class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int point1 = 0;
        int point2 = 0;
        int s1 = name.length();
        int s2 = typed.length();
        if (s2 < s1) {
            return false;
        }
        while (point1 < s1 && point2 < s2) {
            if (name.charAt(point1) == typed.charAt(point2)) {
                point1++;
                point2++;
            } else if (point1 != 0 && name.charAt(point1 - 1) == typed.charAt(point2)) {
                point2++;
            } else {
                return false;
            }
        }
        if (point1 != s1) {
            return false;
        }
        while (point2 != s2) {
            if (point1 != 0 && name.charAt(point1 - 1) == typed.charAt(point2)) {
                point2++;
            } else {
                return false;
            }
        }
        return true;
    }
}