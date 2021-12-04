import java.util.LinkedList;
import java.util.List;

class Solution {

    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        int[] puzz = new int[puzzles.length];
        int[] puzz2 = new int[puzzles.length];
        int[] puzz3 = new int[puzzles.length];
        String curr;
        int currWord;
        for (int i = 0; i < puzzles.length; i++) {
            curr = puzzles[i];
            currWord = 0;
            for (int j = 0; j < curr.length(); j++) {
                currWord |= (1 << (curr.charAt(j) - 97));
            }
            puzz[i] = currWord;
            puzz2[i] = curr.charAt(0) - 97;
        }

        for (int i = 0; i < words.length; i++) {
            curr = words[i];
            currWord = 0;
            for (int j = 0; j < curr.length(); j++) {
                currWord |= (1 << (curr.charAt(j) - 97));

            }
            for (int j = 0; j < puzz.length; j++) {
                if (((currWord >> puzz2[j]) & 1) == 1) {
                    if ((puzz[j] & currWord) == currWord) {
                        puzz3[j]++;
                    }
                }
            }
        }
        List<Integer> list = new LinkedList<>();
        for (int i = 0; i < puzz3.length; i++) {
            list.add(puzz3[i]);
        }
        return list;
    }
}
