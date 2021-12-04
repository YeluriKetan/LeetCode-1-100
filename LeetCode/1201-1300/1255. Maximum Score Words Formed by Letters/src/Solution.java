import java.util.Arrays;

class Solution {

    private static char[][] givenWords;
    private static int[] givenLetters;
    private static int[] givenScore;

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        givenScore = score;
        givenLetters = new int[26];
        for (int i = 0; i < letters.length; i++) {
            givenLetters[letters[i] - 97]++;
        }
        givenWords = new char[words.length][];
        for (int i = 0; i < words.length; i++) {
            givenWords[i] = words[i].toCharArray();
        }
        return helper(0);
    }

    private int helper(int index) {
        int scoreWithout = 0;
        if (index + 1 < givenWords.length) {
             scoreWithout = helper(index + 1);

        }

        char[] split = givenWords[index];
        for (int i = 0; i < split.length; i++) {
            if (givenLetters[split[i] - 97] > 0) {
                givenLetters[split[i] - 97]--;
            } else {
                for (int j = 0; j < i; j++) {
                    givenLetters[split[j] - 97]++;
                }
                return scoreWithout;
            }
        }
        int scoreWith = 0;
        if (index + 1 < givenWords.length) {
            scoreWith = helper(index + 1);
        }

        int curr = 0;
        for (int i = 0; i < split.length; i++) {
            curr += givenScore[split[i] - 97];
            givenLetters[split[i] - 97]++;
        }
        return Math.max(scoreWithout, curr + scoreWith);
    }
}