class Solution {
    public int firstUniqChar(String s) {
        int[] arr = new int[26];
        int curr;
        for (int i = 0; i < s.length(); i++) {
            curr = s.charAt(i) - 97;
            if (arr[curr] == 0) {
                arr[curr] = i + 1;
            } else if (arr[curr] > 0) {
                arr[curr] = -1;
            }
        }
        curr = Integer.MAX_VALUE;
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0 && arr[i] < curr) {
                curr = arr[i];
            }
        }
        return curr == Integer.MAX_VALUE ? -1 : curr - 1;
    }
}
