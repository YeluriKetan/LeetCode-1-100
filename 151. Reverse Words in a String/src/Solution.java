class Solution {
    public String reverseWords(String s) {
        StringBuilder str = new StringBuilder();
        int i = s.length() - 1;
        boolean check = false;
        while (i > -1) {
            if (s.charAt(i) == ' ') {
                if (check) {
                    int j = i + 1;
                    while (j < s.length() && s.charAt(j) != ' ') {
                        str.append(s.charAt(j));
                        j++;
                    }
                    str.append(' ');
                    check = false;
                }
            } else {
                if (!check) {
                    check = true;
                }
            }
            i--;
        }
        if (s.charAt(0) != ' ') {
            int j = i + 1;
            while (j < s.length() && s.charAt(j) != ' ') {
                str.append(s.charAt(j));
                j++;
            }
        } else {
            str.deleteCharAt(str.length() - 1);
        }
        return str.toString();
    }
}