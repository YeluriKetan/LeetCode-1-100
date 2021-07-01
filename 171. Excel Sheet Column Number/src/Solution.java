class Solution {
    public int titleToNumber(String columnTitle) {
        char[] arr = columnTitle.toCharArray();
        int a = 0;
        for (int i = 0; i < arr.length; i++) {
            a *= 26;
            a += arr[i] - 64;
        }
        return a;
    }
}