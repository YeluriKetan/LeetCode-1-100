class Solution {
    public int minDistance(String word1, String word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        if (n1 * n2 == 0) {
            return n1 + n2;
        }
        int[] curr = new int[n2];
        int[] prev = new int[n2];
        prev[n2 - 1] = word1.charAt(n1 - 1) == word2.charAt(n2 - 1) ? 0 : 1;
        for (int i = n2 - 2; i >= 0; i--) {
            prev[i] = (word1.charAt(n1 - 1) == word2.charAt(i)) ? (n2 - i - 1) : Math.min(n2 - i, 1 + prev[i + 1]);
        }
        for (int i = n1 - 2; i >= 0; i--) {
            curr[n2 - 1] = word1.charAt(i) == word2.charAt(n2 - 1) ? n1 - i - 1 : Math.min(n1 - i,1 + prev[n2 - 1]);
            for (int j = n2 - 2; j >= 0; j--) {
                if (word1.charAt(i) == word2.charAt(j)) {
                    curr[j] = prev[j + 1];
                } else {
                    curr[j] = 1 + Math.min(prev[j + 1], Math.min(prev[j], curr[j + 1]));
                }
            }
            int[] holder = prev;
            prev = curr;
            curr = holder;
        }
        return prev[0];
    }
}
