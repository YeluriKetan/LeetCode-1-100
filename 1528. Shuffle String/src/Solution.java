class Solution {
    public String restoreString(String s, int[] indices) {
        char[] newStr = new char[s.length()];
        for (int i = 0; i < newStr.length; i++) {
            newStr[indices[i]] = s.charAt(i);
        }
        return new String(newStr);
    }
}