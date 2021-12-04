class Solution {
    public boolean buddyStrings(String a, String b) {
        if (a.length() != b.length()) {
            return false;
        }
        boolean put1 = false;
        char[] arr3 = new char[28];
        arr3[27] = '.';
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == b.charAt(i)) {
                if (!put1) {
                    if (arr3[(int) b.charAt(i) - 97] == 1) {
                        put1 = true;
                    } else {
                        arr3[(int) b.charAt(i) - 97] = 1;
                    }
                }
            } else {
                if (arr3[27] != '+') {
                    if (arr3[27] == '.') {
                        arr3[26] = a.charAt(i);
                        arr3[27] = b.charAt(i);
                    } else if (a.charAt(i) == arr3[27] && b.charAt(i) == arr3[26]) {
                        arr3[27] = '+';
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (arr3[27] == '.') {
            return put1;
        } else if (arr3[27] == '+') {
            return true;
        } else {
            return false;
        }
    }
}