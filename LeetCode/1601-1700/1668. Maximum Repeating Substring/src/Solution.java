class Solution {
    public int maxRepeating(String sequence, String word) {
        char max = 0;
        char count = 0;
        for (int i = 0; i < sequence.length(); i++) {
            if (sequence.charAt(i) == word.charAt(0) && sequence.startsWith(word, i)) {
                count++;
                i += word.length() - 1;
            } else {
                if (count > 0) {
                    i -= word.length();
                    max = (char) Math.max(count, max);
                    count = 0;
                }
            }
        }
        max = (char) Math.max(count, max);
        return max;
    }
}