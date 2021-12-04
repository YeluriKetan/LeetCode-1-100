import java.util.HashSet;

class Solution {
    private static String str;

    public String longestDupSubstring(String s) {
        str = s;
        int high = s.length();
        int low = 0;
        int mid = 0;
        String result = "";
        String curr;
        while (low < high) {
            mid = (high + low) / 2;
            curr = check(mid);
            if (curr == null) {
                high = mid;
            } else {
                result = curr;
                low = mid + 1;
            }
        }
        return result;
    }

    private String check(int len) {
        HashSet<Long> set = new HashSet<>();
        long pow = 1;
        long hash = 0;
        for (int i = 0; i < len; i++) {
            hash = ((hash * 31) + str.charAt(i));
            pow = (pow * 31);
        }
        set.add(hash);
        for (int i = len; i < str.length(); i++) {
            hash = ((hash * 31) - ((str.charAt(i - len)) * pow) + str.charAt(i));
            if (set.contains(hash)) {
                return str.substring(i - len + 1, i + 1);
            } else {
                set.add(hash);
            }
        }
        return null;
    }
}
