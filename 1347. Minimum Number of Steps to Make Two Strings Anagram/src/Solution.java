class Solution {
    public int minSteps(String s, String t) {
        char count = 0;
        char[] sarr = s.toCharArray();
        char[] tarr = t.toCharArray();
        char[] ref = new char[26];
        for (int i = 0; i < sarr.length; i++) {
            ref[sarr[i] - 97]++;
        }
        for (int i = 0; i < sarr.length; i++) {
            if (ref[tarr[i] - 97] == 0) {
                count++;
            } else {
                ref[tarr[i] - 97]--;
            }
        }
        return count;
    }
}