class Solution {
    public String maximumTime(String time) {
        String str;
        if (time.charAt(0) == 63) {
            int comp = time.charAt(1);
            if (comp == 63 || comp < 52) {
                str = "2";
            } else {
                str = "1";
            }
        } else {
            str = "" + time.charAt(0);
        }
        if (time.charAt(1) == 63) {
            if (str.equals("2")) {
                str = str + 3;
            } else {
                str = str + 9;
            }
        } else {
            str = str + time.charAt(1);
        }
        str = str + ':';
        if (time.charAt(3) == 63) {
            str = str + 5;
        } else {
            str = str + time.charAt(3);
        }
        if (time.charAt(4) == 63) {
            str = str + 9;
        } else {
            str = str + time.charAt(4);
        }
        return str;
    }
}