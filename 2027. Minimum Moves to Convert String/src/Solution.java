class Solution {
    public int minimumMoves(String s) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'X') {
                total++;
                i += 2;
            }
        }
        return total;
    }
}
